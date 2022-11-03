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


int n, d;
vector<int> g[3333];

int dp[3003][3003];

void dfs(int v = 0) {

  for (int to : g[v]) {
    dfs(to);
  }

  for (int w = 1; w <= n + 1; ++w) {
    dp[v][w] = 1;
    for (int to : g[v]) dp[v][w] = mult(dp[v][w], dp[to][w]);
    add(dp[v][w], dp[v][w - 1]);
  }

}


int BASE[6666];

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> d;

  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    g[x - 1].pb(i - 1);
  }

  dfs();

  int res = 0;

  int* kek = BASE + 3333;

  for (int i = -3005; i <= 3005; ++i) kek[i] = bp((i + mod) % mod, mod - 2);


  for (int i = 1; i <= n + 1; ++i) {
    int val = dp[0][i];
    
    for (int j = 1; j <= n + 1; ++j) if (i != j) {
      int now = d;
      dec(now, j);
      now = mult(now, kek[i - j]);
      val = mult(val, now);
    }

    add(res, val);
  }


  cout << res;

}