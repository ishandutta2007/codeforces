#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {

  int A = min(a.x, a.y);
  int B = min(b.x, b.y);

  if (A != B) return (A < B);
  A = (a.y == min(a.x, a.y));
  B = (b.y == min(b.x, b.y));

  return (A > B);

}

vector<int> rmq;
vector<int> p;

void push(int i, int l, int r) {

  if (r - l <= 1) return;

  int P = p[i];
  p[i] = 0;

  rmq[2*i+1] += P, p[2*i+1] += P;
  rmq[2*i+2] += P, p[2*i+2] += P;

}

void upd(int i, int l, int r, int index, int x) {

  push(i, l, r);

  if (r - l == 1) {
    rmq[i] = x;
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index, x);
  else upd(2*i+2, mid, r, index, x);

  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

int get(int i, int l, int r, int l1, int r1) {

  push(i, l, r);
  if (l1 >= r1) return -1e9;

  if (l == l1 && r == r1) { 
    return rmq[i];
  }
  int mid = (l+r)/2;
  return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));
}

void add(int i, int l, int r, int l1, int r1) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    rmq[i]++;
    p[i]++;
    return;
  }

  int mid = (l+r)/2;
  add(2*i+1, l, mid, l1, min(r1, mid));
  add(2*i+2, mid, r, max(l1, mid), r1);

  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, d;
  cin >> n >> d;

  vector<pair<int, int> > v(n);
  for (auto &x : v) {
    cin >> x.x >> x.y;
  }

  sort(all(v), cmp);
  vector<int> last;

  last.pb(d);
  for (auto x : v) last.pb(x.y);

  sort(all(last));

  last.resize(unique(all(last)) - last.begin());
  
  rmq.assign(4*n + 4, -1e9);
  p.assign(4 * n + 4, 0);

  upd(0, 0, n + 1, lower_bound(all(last), d) - last.begin(), 0);

//  per(v);
 // per(last);

  for (int i = 0; i < n; ++i) {
    int S = lower_bound(all(last), v[i].x + 1) - last.begin();
    int D = lower_bound(all(last), v[i].y + 1) - last.begin();

    int can = get(0, 0, n + 1, 0, min(S, D));
    upd(0, 0, n + 1, D - 1, can + 1);

    add(0, 0, n + 1, D, S);
  }

  cout << rmq[0];


}