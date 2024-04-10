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

struct Seg {
  int l;
  int r;
  int opposite;
};

vector<vector<Seg> > one;
vector<vector<Seg> > two;
vector<bool> dused;

vector<int> current;

int start;

void dfs(int vertex, int kek) {
  dused[vertex] = 1;
  current.pb(vertex);
  for (auto e : one[vertex]) {
    int W = e.opposite;
    if (e.l == kek) continue;
    if (dused[W]) {
      start = vertex;
      continue;
    }
    dfs(W, e.l);
  }
} 

vector<int> v;

void add_seg(int l, int r, int x) {
  if (v[l - 1] == x) v[l] = x;
  else v[r] = x;
}

void dfs2(int vertex, int is_start) {
  dused[vertex] = 1;
  for (auto e : one[vertex]) {
    int W = e.opposite;
    if (dused[W]) {
      if (is_start) {
        add_seg(e.l, e.r, vertex);
      }
      continue;
    }
    add_seg(e.l, e.r, W);
    dfs2(W, 0);
  }
}

struct GeneralMatching{
  static const int MAXN = 50000; //choose MAXN here
  // call init(n, edges)
  // blossom() gives the list of max-matching edges
  vector<int>g[MAXN];
  int pa[MAXN],match[MAXN],st[MAXN],S[MAXN],v[MAXN];
  int t,Q;
  inline int lca(int x,int y){
    for(++t;;swap(x,y)){
      if(x==0)continue;
      if(v[x]==t)return x;
      v[x]=t;
      x=st[pa[match[x]]];
    }
  }
  #define qpush(x) q.push(x),S[x]=0
  void flower(int x,int y,int l,queue<int> &q){
    while(st[x]!=l){
      pa[x]=y;
      y=match[x];
      if(S[y]==1) qpush(y);
      st[x]=st[y]=l;
      x=pa[y];
    }
  }
  bool bfs(int x){
    for(int i=1;i<=Q;++i)st[i]=i;
    memset(S+1,-1,sizeof(int)*Q);
    queue<int>q;
    qpush(x);
    while(q.size()){
      x=q.front(),q.pop();
      for(size_t i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(S[y]==-1){
          pa[y]=x;
          S[y]=1;
          if(!match[y]){
            for(int lst;x;y=lst,x=pa[y]){
              lst=match[x];
              match[x]=y;
              match[y]=x;
            }
            return 1;
          }
          qpush(match[y]);
        } else if(!S[y]&&st[y]!=st[x]){
          int l=lca(y,x);
          flower(y,x,l,q);
          flower(x,y,l,q);
        }
      }
    }
    return 0;
  }
  vector<pair<int, int> > blossom(){ //returns result in 1-indexation
    int ans=0;
    for(int i=1;i<=Q;++i)
      if(!match[i]&&bfs(i))++ans;
    
    vector<pair<int, int> > res;
    for (int i = 1; i <= Q; ++i) {
      if (match[i] != 0 && i < match[i]) {
        res.push_back({i - 1, match[i] - 1});
      }
    }

    return res;

  }

  GeneralMatching(int n, vector<pair<int, int> > edges) { //1-indexation
    Q = n;
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].first + 1;
      int v = edges[i].second + 1;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }

};

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  v.resize(n);
  for (auto &x : v) cin >> x;

  vector<bool> used(n + 1, false);
  one.assign(n + 1, {});
  two.assign(n + 1, {});

  for (int i = 0; i < n; ++i) {
    if (v[i] == 0 && (i == 0 || v[i - 1] > 0)) {
      int j = i + 1;
      while (j < n && v[j] == 0) j++;
      --j;
      if ((j % 2) == (i % 2)) { /////////uneven len
        if (i == 0 && j == n - 1) {
          continue;
        }
        if (i == 0) {
          v[j] = v[j + 1];
        }
        else if (j == n - 1) {
          v[i] = v[i - 1];
        }
        else {
          int a = v[i - 1], b = v[j + 1];
          one[a].pb({i, j, b});
          one[b].pb({i, j, a});
        }
      }
      else {
        if (i == 0 || j == n - 1) {
          continue;
        }
        int a = v[i - 1], b = v[j + 1];
        two[a].pb({i, j, b});
        two[b].pb({i, j, a});
      }
    }
  }

  dused.assign(n + 1, false);

  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1] && v[i] > 0) used[v[i]] = 1;
  }

  vector<vector<int> > bad_compontents;

  for (int i = 1; i <= n && i <= 600; ++i) {
    if (dused[i]) continue;

    current.clear();
    start = -1;

    dfs(i, -1);

    for (auto x : current) if (used[x]) start = x;
    if (start == -1) {
      bad_compontents.pb(current);
    }
    else {
      for (auto x : current) dused[x] = false;
      dfs2(start, 1);
    }
  }


  vector<int> index(n + 1, -1);
  for (int i = 0; i < bad_compontents.size(); ++i) {
    for (auto x : bad_compontents[i]) index[x] = i;
  }

  int N = bad_compontents.size();
  vector<pair<int, int> > edges;

  map<pair<int, int>, int> ae;
  vector<pair<int, int> > taken;
  vector<pair<int, int> > seg;

  for (int i = 1; i <= n; ++i) {
    for (auto x : two[i]) {
      int W = x.opposite;
      if (index[i] == -1 || index[W] == -1) continue;

      int A = index[i], B = index[W];

      if (A >= B) continue;
      if (ae.count(mp(A, B))) continue;

      ae[mp(A, B)] = edges.size();
      edges.pb(mp(A, B));
      taken.pb(mp(i, W));
      seg.pb(mp(x.l, x.r));
    }
  }

  GeneralMatching g(N, edges);
  auto res = g.blossom();

  vector<bool> kused(N, false);
  for (auto ee : res) {
    kused[ee.x] = 1;
    kused[ee.y] = 1;

    if (ee.x > ee.y) swap(ee.x, ee.y);
    int R = ae[ee];
    int A = taken[R].x, B = taken[R].y;
    int C = seg[R].x, D = seg[R].y;

    v[C] = v[C - 1];
    v[D] = v[D + 1];

    for (auto x : bad_compontents[ee.x]) dused[x] = 0;
    dfs2(A, 1);
    for (auto x : bad_compontents[ee.y]) dused[x] = 0;
    dfs2(B, 1);
  }

  for (int i = 0; i < bad_compontents.size(); ++i) {
    if (!kused[i]) {
      for (auto x : bad_compontents[i]) dused[x] = 0;
      dfs2(bad_compontents[i][0], 1);
    }
  }

  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1] && v[i] > 0) used[v[i]] = 1;
  }

  vector<int> nn;
  for (int i = 1; i <= n; ++i) if (!used[i]) nn.pb(i);

  int cur = 0;
  while (cur + 1 < n) {
    if (v[cur] == 0 && v[cur + 1] == 0) {
      int W = nn.back();
      v[cur] = W;
      v[cur + 1] = W;
      cur += 2;
      nn.pop_back();
    } 
    else {
      if (v[cur] == 0) v[cur] = 1;
      cur++;
    }
  }

  if (v.back() == 0) v.back() = 1;
  for (auto x : v) cout << x << " ";


  

}