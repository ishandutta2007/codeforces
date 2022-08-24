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

vector<vector<int> > gr;
vector<int> v;
vector<int> h;

void dfs(int vertex, int last, int d) {

  h[vertex] = d;

  for (auto to : gr[vertex]) {
    if (to == last) continue;
    dfs(to, vertex, d + 1);
  }

}

vector<int> ans;
vector<vector<pair<int, int> > > queries;

void dfs2(int vertex, int last, vector<int> &p) {

  int tut = 0;
  int take = 0;
  p.pb(v[vertex]);

  int now = p.size() - 1;

  for (auto tt : queries[vertex]) {
    for (int j = take; j < tt.x; ++j) tut = max(tut, p[now--] ^ j);
    take = tt.x;
    ans[tt.y] = tut;
  }

  for (auto to : gr[vertex]) {
    if (to == last) continue;
    dfs2(to, vertex, p);
  }

  p.pop_back();

}

int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;


  gr.assign(n, {});
  v.assign(n, -1);

  for (auto &x : v) cin >> x;
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    gr[u].pb(v), gr[v].pb(u);
  }

  h.assign(n, -1);

  dfs(0, -1, 0);
  ans.assign(q, -1);

  queries.assign(n, {});
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    queries[v].pb(mp(h[v] - h[u] + 1, i));
  }

  for (auto &x : queries) sort(all(x));
  vector<int> p;

  dfs2(0, -1, p);
  for (auto x : ans) cout << x << " ";

  

}