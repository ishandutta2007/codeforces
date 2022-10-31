#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii> > graph;

graph G;
int n,m;
int e[100005];
int flp[100005];
const int INF = 0x7fffffff;
int vis[100005],vis2[100005];
bool chk[100005];
int tag[100005];

vector<int> x;
vector<int> y;

int tmpa;
int sz = 0;
void recurse(const int& v,const int& p) {
  vis[v] = 1;
  ++sz;
  for(int i = 0; i < G[v].size(); ++i) {
    if(vis[G[v][i].first]) continue;
    if((flp[v]^e[G[v][i].second]) != p) {
      ++tmpa;
      flp[G[v][i].first] = 1;
    }
    recurse(G[v][i].first,p);
  }
}

void flipall(const int&v) {
  vis2[v]=1;
  flp[v]^=1;
  for(int i = 0; i < G[v].size(); ++i) {
    if(vis2[G[v][i].first]) continue;
    flipall(G[v][i].first);
  }
}

bool calc(const int& p, vector<int>& ans) {
  for(int i = 0; i < m; ++i)
    flp[i] = 0;
  fill(vis,vis+n,0);
  fill(vis2,vis2+n,0);
  for(int v = 0; v < n; ++v) {
    if(vis[v]) continue;
    flp[v] = 1;
    vis[v] = 1;
    tmpa = 1;
    sz = 1;
    for(int i = 0; i < G[v].size(); ++i) {
      pii ed = G[v][i];
      if(vis[ed.first]) continue;
      if((!e[ed.second]) != p) {
        ++tmpa;
        flp[ed.first] = 1;
      }
      recurse(ed.first,p);
    }
    if(sz-tmpa < tmpa)
      flipall(v);
  }
  fill(chk,chk+m,0);
  for(int v = 0; v < n; ++v) {
    for(int i = 0; i < G[v].size(); ++i) {
      chk[G[v][i].second] ^= flp[v];
    }
  }
  for(int i = 0; i < m; ++i)
    if((chk[i]^e[i]) != p) return false;
  for(int i = 0; i < n; ++i)
    if(flp[i]) ans.push_back(i);
  return true;
}

void prnv(const vector<int>& v) {
  cout << v.size() << "\n";
  for(int i = 0; i < v.size(); ++i)
    cout << v[i]+1 << ((i==v.size()-1)?"\n":" ");
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  G = graph(n,vector<pii>());
  for(int i = 0; i < m; ++i) {
    int u,v;
    char c;
    cin >> u >> v >> c;
    e[i] = c == 'R';
    G[--u].push_back(pii(--v,i));
    G[v].push_back(pii(u,i));
  }
  // cout << "done reading" << endl;
  bool a = calc(0,x);
  bool b = calc(1,y);
  if(!a && !b) cout << "-1\n";
  else if(!a) prnv(y);
  else if(!b) prnv(x);
  else {
    if(x.size() < y.size()) prnv(x);
    else prnv(y);
  }
  return 0;
}