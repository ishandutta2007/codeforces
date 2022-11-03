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

//    ,    -   S,     .
//     A    B,     S  B   A.
// idom[v] - the parent of vertex v in the dominator tree
// !WARNING! be careful if a graph is somehow unconnected (depends on a task) 

struct DominatorTree{
    struct DSU{
        struct Vert{
            int p;
            pair<int, int> val;
        };

        vector<Vert> t;
        vector<int> ord;

        DSU(vector<int> &ord): ord(ord) { t.resize(ord.size()); for (int i = 0; i < ord.size(); i++) t[i].p = i; }

        int get(int v){
                if (t[v].p == v) return v;
                int new_p = get(t[v].p);
                if (ord[t[v].val.first] > ord[t[t[v].p].val.first]) t[v].val = t[t[v].p].val;
                t[v].p = new_p;
                return t[v].p;
        }

        void merge(int a, int b){
            a = get(a); b = get(b);
            if (a != b){
                t[b].p = a;
            }
        }

        void setVal(int v, pair<int, int> val){
            t[v].val = val;
        }

        pair<int, int> getVal(int v){
            get(v);
            return t[v].val;
        }
    };

    vector<vector<int> > g, gr, lg;
    vector<int> idom, sdom, was, tin;

    int timer;
    void dfs(int v){
        tin[v] = timer++;
        was[v] = 1;
        for (int to : g[v]) if (!was[to]) dfs(to);
    }

    vector<vector<int> > req;

    DominatorTree(int n, vector<pair<int, int> > &edges, int root){
        g.resize(n); gr.resize(n); lg.resize(n);
        idom.resize(n, -1); sdom.resize(n);
        was.resize(n, 0), tin.resize(n);
        req.resize(n);
        for (auto &&e : edges){
            g[e.first].push_back(e.second);
            gr[e.second].push_back(e.first);
        }
        timer = 0; dfs(root);
        vector<int> ord;
        for (int i = 0; i < n; i++) ord.push_back(i);
        sort(ord.begin(), ord.end(), [this](int w1, int w2){ return tin[w1] > tin[w2]; });
        DSU dsu(tin);
        for (int v : ord){
            sdom[v] = v;
            for (int to : gr[v]){
                if (v == to) continue;
                int val = tin[to] < tin[v] ? to : dsu.getVal(to).first;
                if (tin[val] < tin[sdom[v]]) sdom[v] = val;
            }

            req[sdom[v]].push_back(v);
            for (auto &&r : req[v]){
                auto val = dsu.getVal(r);
                if (tin[val.first] < tin[sdom[r]]){
                    lg[val.second].push_back(r);
                } else {
                    idom[r] = sdom[r];
                }
            }

            dsu.setVal(v, make_pair(sdom[v], v));
            for (int to : g[v]){
                if (tin[to] > tin[v] && dsu.t[to].p == to){
                    dsu.merge(v, to);
                }
            }
        }

        for (int i = 0; i < n; i++) was[i] = 0;

        for (int i = 0; i < n; i++) if (!was[i] && idom[i] != -1){
            vector<int> st;
            st.push_back(i);
            was[i] = 1;
            while(st.size()){
                int v = st.back(); st.pop_back();
                idom[v] = idom[i];
                for (int to : lg[v]) if (!was[to]) was[to] = 1, st.push_back(to);
            }
        }
    }
};

int n, m, s;
vector<pair<int, int> > g[200007];

ll d[200007];

vector<int> r[200007];

int dp[200007];

void dfs(int v) {
  dp[v] = 1;
  for (int to : r[v]) {
    dfs(to);
    dp[v] += dp[to];
  }
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> s; --s;
  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    g[w1].pb(mp(w2, w3));
    g[w2].pb(mp(w1, w3));
  }

  const ll LINF = 1e18 + 7;
  fill(d, d + 200007, LINF);

  d[s] = 0;
  set<pair<ll, int> > se;
  se.insert(mp(0, s));

  while (se.size()) {
    auto now = *se.begin();
    se.erase(se.begin());

    for (auto [to, w] : g[now.y]) if (d[to] > now.x + w) {
      se.erase(mp(d[to], to));
      d[to] = now.x + w;
      se.insert(mp(d[to], to));
    }
  }

 // for (int v = 0; v < n; ++v) cout << d[v] << ' '; cout << endl;

  vector<pair<int, int> > ed;
  for (int v = 0; v < n; ++v) {
    for (auto [to, w] : g[v]) if (d[to] == d[v] + w) ed.pb(mp(v, to)); //, per(v, to);
  }

  auto dm = DominatorTree(n, ed, s);

//  pper(dm.idom)

  for (int v = 0; v < n; ++v) if (v != s) {
    r[dm.idom[v]].pb(v);
  }

  dfs(s);

  int ma = 0;
  for (int v = 0; v < n; ++v) if (v != s) uax(ma, dp[v]);

  cout << ma;

}