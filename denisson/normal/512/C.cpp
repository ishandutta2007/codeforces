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


#define pb push_back

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
        for (minFlow = 1; minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;



int n;
int a[222];

bool isPr(int x) {
  for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
  return x > 1;
}

vector<int> g[222];
bool was[222];

int main(){
#ifdef LOCAL
	freopen("P_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  vector<int> t1, t2;
  for (int i = 0; i < n; ++i) if (a[i] % 2 == 0) t1.pb(i); else t2.pb(i);

  if (t1.size() != t2.size()) {
    cout << "Impossible"; exit(0);
  }

  int start = n, finish = n + 1;

  for (int i = 0; i < t1.size(); ++i) {
    dinic.addEdge(start, t1[i], 2);
    dinic.addEdge(t2[i], finish, 2);
  }

  for (int i = 0; i < t1.size(); ++i)
  for (int j = 0; j < t2.size(); ++j) {
    if (isPr(a[t1[i]] + a[t2[j]])) dinic.addEdge(t1[i], t2[j], 1);
  }

  if (dinic.dinic(start, finish) != n) {
    cout << "Impossible"; exit(0);
  }

  vector<vector<int>> res;

  for (int v : t1) {
    for (int to : dinic.g[v]) if (dinic.e[to].flow > 0 && dinic.e[to].to < n) {
      g[v].pb(dinic.e[to].to);
      g[dinic.e[to].to].pb(v);
    }
  }


  for (int i = 0; i < n; ++i) if (!was[i]) {
    int v = i;
    vector<int> now;

    while (!was[v]) {
      was[v] = 1;
      now.pb(v);
      if (!was[g[v][0]]) v = g[v][0]; else v = g[v][1];
    }


    res.pb(now);
  }


  cout << res.size() << "\n";
  for (auto&& x : res) {
    cout << x.size() << ' ';
    for (int y : x) cout << y + 1 << ' ';
    cout << "\n";
  }

}