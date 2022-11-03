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

void solve() {
  int n; cin >> n;
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x == 1) {
      st.pb(1);
    } else {while (st.back() + 1 != x) st.pop_back();
    st.back()++; }

    for (int j = 0; j < st.size(); ++j) {
      cout << st[j];
      if (j + 1 != st.size()) cout << ".";
    }
      cout << "\n";
  }
}

int n, m, p;

string a[200007];

int dp[1 << 15];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> p;
  readArr(a, a + n);

  int ans_cnt = -1;
  string res;

  for (int it = 0; it < 60; ++it) {

    int v = myRand32() % n;

    vector<int> d;

    for (int j = 0; j < m; ++j) if (a[v][j] == '1') d.pb(j);


    std::fill(dp, dp + (1 << d.size()), 0);

    for (int i = 0; i < n; ++i) {
      int now = 0;

      for (int j = 0; j < d.size(); ++j) if (a[i][d[j]] == '1') now ^= 1 << j;

      dp[now]++;
    }

    for (int j = 0; j < d.size(); ++j) {
      for (int mask = 0; mask < (1 << d.size()); ++mask) if ((mask >> j) & 1) {
        dp[mask ^ (1 << j)] += dp[mask];
      }
    }

    for (int mask = 0; mask < (1 << d.size()); ++mask) if (dp[mask] >= ((n + 1) >> 1)) {
      int cnt_now = __builtin_popcount(mask);
      if (cnt_now > ans_cnt) {
        ans_cnt = cnt_now;
        string kek; for (int j = 0; j < m; ++j) kek += '0';
        for (int j = 0; j < d.size(); ++j) if ((mask >> j) & 1) kek[d[j]] = '1';
        res = kek;
      }
    }

  }

  cout << res;
}