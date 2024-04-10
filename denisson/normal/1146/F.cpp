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

const int mod = 998244353;

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

int n;
vector<int> g[200007];

int dp1[200007];
int dp2[200007];

void dfs(int v = 0) {

  if (g[v].size() == 0) {
    dp1[v] = dp2[v] = 1;
    return;
  }

  vector<int> t;

  for (int to : g[v]) {
    dfs(to);
    t.pb(dp1[to]);
  }

  for (int i = 1; i < t.size(); ++i) t[i] = mult(t[i], t[i - 1]); 

  add(dp1[v], t.back());
  
  
  int sum = 0;
  int pr = 1;

  for (int i = (int)g[v].size() - 1; i >= 0; --i) {
    int to = g[v][i];

    int coef = 1;
    if (i > 0) coef = t[i - 1];
    add(dp1[v], mult(mult(sum, dp2[to]), coef));


    sum = mult(sum, dp1[to]);

    add(sum, mult(pr, dp2[to]));

    int now = dp1[to];
    add(now, dp2[to]);
    pr = mult(pr, now);

  }

  dp2[v] = pr;
  dec(dp2[v], t.back());

//  per(v, dp1[v], dp2[v]);


}

int main() {
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    g[x - 1].pb(i - 1);
  }

  dfs();

  cout << dp1[0];
}