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

int n, m;
vector<int> g[100007];

int was[100007];
int h[100007];
int tin[100007];
int tout[100007];

int tt = 0;

void dfs(int v, int hh = 0) {
  was[v] = 1;
  tin[v] = tt++;
  h[v] = hh;
  
  for (int to : g[v]) if (!was[to]) {
    dfs(to, hh + 1);
  }

  tout[v] = tt++;
}

bool isPred(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int dd[100007];
int dp[100007];
int bad[100007];

void go(int v) {
  dp[v] = dd[v];
  for (int to : g[v]) if (h[to] == h[v] + 1) {
    go(to);
    dp[v] += dp[to];
  }
}

int jump[100007];
set<int> se[100007];

void kek(int v) {
  bad[v] = dp[v] >= 2;

  for (int to : g[v]) if (h[to] == h[v] + 1) {

    kek(to);

    if (se[to].size() < se[v].size()) swap(se[to], se[v]);
    for (int x : se[to]) se[v].insert(x);

    se[v].erase(v);

  } else se[v].insert(to);

  if (se[v].size() == 1) jump[v] = *se[v].begin();
}


void kek2(int v) {

  if (dp[v] == 1 && bad[jump[v]]) bad[v] = 1;

//  per("=====  ", v + 1, jump[v] + 1, bad[jump[v]], bad[v]);

  for (int to : g[v]) if (h[to] == h[v] + 1) {
    kek2(to);
  }

}



void solve() {

  cin >> n >> m;

  for (int i = 0; i < n; ++i) g[i].clear(), se[i].clear();

  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2; --w1; --w2;
    g[w1].pb(w2);
  }

  int start = -1;

  for (int it = 0; it < 99; ++it) {

    int v = myRand32() % n;

    fill(was, was + n, 0);
    tt = 0;

    dfs(v);

    int ok = 1;

    for (int v = 0; v < n; ++v) {
      for (int to : g[v]) {

        if (!isPred(v, to) && !isPred(to, v)) ok = 0;

        if (h[v] + 1 < h[to]) ok = 0;

      }
    }

    if (ok) {
      start = v;
      break;
    }

  }

  if (start == -1) {
    cout << "-1\n";
    return;
  }

  fill(dd, dd + n, 0);
  fill(dp, dp + n, 0);
  fill(bad, bad + n, 0);

  // pper(start + 1);

  for (int v = 0; v < n; ++v) {
    for (int to : g[v]) if (h[v] > h[to]) {

      dd[v]++;
      dd[to]--;

     // per(v + 1, to + 1);

    }
  }

  go(start);
  kek(start);
  kek2(start);


  for (int v = 0; v < n; ++v) {
  //  per(v + 1, dp[v], jump[v] + 1);
  }


  vector<int> res;
  for (int v = 0; v < n; ++v) if (!bad[v]) res.pb(v);

  if (res.size() * 5 < n) {
    cout << "-1\n";
  } else {
    for (int v : res) cout << v + 1 << ' '; cout << "\n";
  }
}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}