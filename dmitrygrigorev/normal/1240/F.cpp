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

vector<vector<pair<int, int> > > gr;

void read_trash() {
  int x;
  cin >> x;
}

vector<int> ans;
int n, m;

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 555; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    void add(int a, int b, int l, int r, int z) {
      addEdge(a + 1, b + 1, r - l);
      addEdge(0, b + 1, l);
      addEdge(a + 1, z, l);
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = (1 << 30); minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
};

Dinic dinic;

void solve(int k) {

  if (k == 1) {
    for (auto &x : ans) if (x == -1) x = 1;
    return;
  }

  vector<int> deg(2*n, 0);
  for (int i = 0; i < n; ++i) for (auto p : gr[i]) {
    deg[i]++;
    deg[n + p.x]++;
  }

  dinic.clear();

  vector<int> need;

  for (int i = 0; i < n; ++i) {
    int A = deg[i] / k, B = (deg[i] + k - 1) / k;
    dinic.add(0, i + 1, A, B, 2*n+3);
    for (auto to : gr[i]) {
      need.pb(dinic.e.size());
      dinic.add(i + 1, n + to.x + 1, 0, 1, 2*n+3);
    }
  }

  for (int i = n; i < 2*n; ++i) {
    int A = deg[i] / k, B = (deg[i] + k - 1) / k;
    dinic.add(i + 1, 2*n + 1, A, B, 2*n+3);
  }

  dinic.add(2*n+1, 0, 0, 1000000, 2*n+3);

  dinic.dinic(0, 2*n+3);

  set<int> taken;
  int u = 0;

  vector<vector<pair<int, int> > > nn(n);

  for (int i = 0; i < n; ++i) {
    for (auto to : gr[i]) {
      //per(need[u], dinic.e.size());
      if (dinic.e[need[u]].flow) {
        taken.insert(to.y);
      }
      else nn[i].pb(to);
      u++;
    }
  }

  for (auto x : taken) ans[x] = k;

  gr = nn;


  solve(k - 1);

}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k;

  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) read_trash();

  gr.assign(n, {});

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (x > y) swap(x, y);
    gr[x].pb(mp(y, i));
  }

  ans.assign(m, -1);
  solve(k);

  for (auto x : ans) cout << x << '\n';

}