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

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<char> > v(n);
  for (auto &x : v) x.assign(m, ' ');

  for (auto &x : v) for (auto &y : x) cin >> y;

  vector<vector<int> > min_x(n), min_y(n);
  for (auto &x : min_x) x.assign(m, -1);
  for (auto &x : min_y) x.assign(m, -1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      min_x[i][j] = i, min_y[i][j] = j;
      if (i > 0 && v[i - 1][j] == '.') {
        min_x[i][j] = min(min_x[i][j], min_x[i - 1][j]);
        min_y[i][j] = min(min_y[i][j], min_y[i - 1][j]);
      }
      if (j > 0 && v[i][j - 1] == '.') {
        min_x[i][j] = min(min_x[i][j], min_x[i][j - 1]);
        min_y[i][j] = min(min_y[i][j], min_y[i][j - 1]);
      }
    }
  }

  vector<int> bad(m, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (min_x[i][j] != 0) {
        bad[j] = max(bad[j], min_y[i][j]);
      }
    }
  }

  vector<int> can(m);

  int now = 0;
  for (int i = 0; i < m; ++i) {
    while (now < m && bad[now] <= i) now++;
    can[i] = now;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    if (r <= can[l]) cout << "YES\n";
    else cout << "NO\n";
  }

}