#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


const int N = 200;

int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; }while (v != u);
    ++scompNum; }}
void get_scc(int n) {
  memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

bool truth[N/2]; // N must be at least 2 times the number of variables
// the clause a || b becomes !a => b and !b => a in implication graph
void add_clause(int a, int b) {
  adj[a^1].push_back(b); adj[b^1].push_back(a); }
bool two_sat(int n) { get_scc(n);
  for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return 0;
    truth[i/2] = (scomp[i] < scomp[i^1]); } return 1; }

int val[10100];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;

  for (int i=0; i<3; ++i) {
    int a, o;
    cout << "and "<< (i+1) << " " << (i+1)%3 + 1 << endl;
    cin >> a;
    cout << "or "<< (i+1) << " " << (i+1)%3 + 1 << endl;
    cin >> o;
    for (int j=0; j<30; ++j) {
      int x = (i*30 + j);
      int y = (((i+1)%3)*30 + j);
      if ((a&(1<<j)) && (o&(1<<j))) {
        adj[x*2].push_back(x*2+1);
        adj[y*2].push_back(y*2+1);
      } else if (!(a&(1<<j)) && !(o&(1<<j))) {
        adj[x*2+1].push_back(x*2);
        adj[y*2+1].push_back(y*2);
      } else if (!(a&(1<<j)) && (o&(1<<j))) {
        adj[x*2+1].push_back(y*2);
        adj[x*2].push_back(y*2+1);
        adj[y*2+1].push_back(x*2);
        adj[y*2].push_back(x*2+1);
      } else {
        assert(false);
      }
    }
  }

  bool res = two_sat(182);
  assert(res);
  for (int i=0; i<3; ++i) {
    for (int j=0; j<30; ++j) {
      if (!truth[i*30+j]) {
        val[i+1] |= (1<<j);
      }
    }
  }

  for (int i=4; i<=n; ++i) {
    int a, o;
    cout << "and " << 1 << " " << i << endl;
    cin >> a;
    cout << "or " << 1 << " " << i << endl;
    cin >> o;
    for (int j=0; j<30; ++j) {
      if ( ((val[1]&(1<<j)) && (a&(1<<j)))
        || (!(val[1]&(1<<j)) && (o&(1<<j))) ) {
        val[i] |= (1<<j);
      }
    }
  }

  vector<int> r;
  for (int i=1; i<=n; ++i) {
    r.push_back(val[i]);
  }
  sort(r.begin(), r.end());
  cout << "finish "<< r[k-1] << endl;

  return 0;
}