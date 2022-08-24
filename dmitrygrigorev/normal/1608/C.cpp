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

struct G {
  int x;
  int y;
  int index;
};

bool cmp(G &x, G &y) {
  return (x.x < y.x);
}

bool cmp2(G &x, G &y) {
  return (x.y < y.y);
}

void solve() {

  int n;
  cin >> n;

  vector<G> v(n);
  for (int i = 0; i < n; ++i) {
    v[i].index = i;
    cin >> v[i].x;
  }
  for (int i = 0; i < n; ++i) {
    v[i].index = i;
    cin >> v[i].y;
  }

  vector<int> posy(n);
  sort(all(v), cmp2);
  for (int i = 0; i < n; ++i) posy[v[i].index] = i;

  auto Z = v;

  sort(all(v), cmp);
  vector<bool> win(n, false);

  vector<int> posx(n);
  for (int i = 0; i < n; ++i) posx[v[i].index] = i;

  int now = n;
  int kek = n - 1;

  int go = n - 1;
  int go2 = n - 1;

  while (now > go) {
    now--;
    int p = posy[v[now].index];
    go2 = min(go2, p);
    while (kek >= go2) {
      int R = Z[kek--].index;
      go = min(go, posx[R]);
    }
  }

  for (int i = go; i < n; ++i) win[v[i].index] = true;

  now = n;
  kek = n - 1;

  go = n - 1;
  go2 = n - 1;

  while (now > go) {
    now--;
    int p = posx[Z[now].index];
    go2 = min(go2, p);
    while (kek >= go2) {
      int R = v[kek--].index;
      go = min(go, posy[R]);
    }
  }

  for (int i = go; i < n; ++i) win[Z[i].index] = true;
  for (auto x : win) {
    if (x) cout << 1;
    else cout << 0;
  }
  cout << '\n';



}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}