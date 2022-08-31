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

vector<pair<ll, ll> > rmq;
const ll INF = 1e18;

void build(int i, int l, int r, vector<ll> &v) {
  if (r - l == 1) {
    rmq[i] = mp(v[l], v[l]);
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid, v);
  build(2*i+2, mid, r, v);

  rmq[i].x = min(rmq[2*i+1].x, rmq[2*i+2].x);
  rmq[i].y = max(rmq[2*i+1].y, rmq[2*i+2].y);

}

pair<ll, ll> get(int i, int l, int r, int l1, int r1) {
  if (l1 >= r1) return mp(INF, -INF);
  if (l == l1 && r == r1) return rmq[i];

  int mid = (l+r)/2;
  auto A = get(2*i+1, l, mid, l1, min(r1, mid));
  auto B = get(2*i+2, mid, r, max(l1, mid), r1);
  return mp(min(A.x, B.x), max(A.y, B.y));

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<int> v(n, 0);
  for (auto &x : v) {
    int y;
    cin >> y;
    x -= y;
  }

  for (auto &x : v) {
    int y;
    cin >> y;
    x += y;
  }

  vector<ll> prefix_sum;
  prefix_sum.pb(0);

  for (int i = 0; i < n; ++i) {
    prefix_sum.pb(prefix_sum.back() + v[i]);
  }

  rmq.assign(4*n + 4, mp(INF, -INF));
  build(0, 0, n + 1, prefix_sum);

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (prefix_sum[l] != prefix_sum[r + 1]) {
      cout << "-1\n";
    }
    else {
      ll b = prefix_sum[l];
      auto R = get(0, 0, n + 1, l, r + 2);
      if (R.x < b) {
        cout << "-1\n";
      }
      else {
        cout << R.y-b << '\n';
      }
    }
  }



}