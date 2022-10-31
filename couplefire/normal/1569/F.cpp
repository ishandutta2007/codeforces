#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define fst first
#define snd second

const int maxn = 12;
const int maxm = 6;

int n, m, k;
int fac[maxn + 5];
int f[1 << maxm][maxm];
int used[maxn], vis[maxn];
int ed[maxn][maxn];
vector<vector<int> > part;
set<vector<int> > can;

inline void setPartition(int tot){
  for(int i = 0; i < n / 2; ++i)
    if(!~used[i]){
      for(int j = 0; j <= tot; ++j)
	used[i] = j, setPartition(tot + (j == tot));
      used[i] = -1;
      return;
    }

  vector<int> vec;
  for(int i = 0; i < n / 2; ++i)
    vec.PB(used[i]);
  part.PB(vec);
  return;
}

inline bool check(vector<pair<int, int> > vec){
  memset(f, 0, sizeof(f));
  for(int i = 0; i < vec.size(); ++i)
    if(ed[vec[i].fst][vec[i].snd])
      f[1 << i][i] = true;
  for(int S = 0; S < (1 << vec.size()); ++S)
    for(int i = 0; i < vec.size(); ++i)
      if(f[S][i]){
	for(int j = 0; j < vec.size(); ++j)
	  if(!(S >> j & 1) && (ed[vec[i].fst][vec[j].fst] && ed[vec[i].snd][vec[j].snd] || ed[vec[i].snd][vec[j].fst] && ed[vec[i].fst][vec[j].snd]))
	    f[S ^ (1 << j)][j] = true;
      }
  
  for(int i = 0; i < vec.size(); ++i)
    if(f[(1 << vec.size()) - 1][i])
      return true;
  return false;
}

inline void dfs(vector<pair<int, int> > vec){
  if(vec.size() == n / 2){
    if(check(vec)){
      for(int i = 0; i < part.size(); ++i){
	vector<int> col(n);
	for(int j = 0; j < part[i].size(); ++j)
	  col[vec[j].fst] = col[vec[j].snd] = part[i][j];
	can.insert(col);
      }
    }
    return;
  }
  
  for(int i = 0; i < n; ++i)
    if(!vis[i]){
      for(int j = i + 1; j < n; ++j)
	if(!vis[j]){
	  vector<pair<int, int> > nxt = vec;
	  nxt.PB(MP(i, j));
	  vis[i] = vis[j] = true;
	  dfs(nxt);
	  vis[i] = vis[j] = false;
	}
      return;
    }
  return;
}

int main(){
  //freopen("main.in", "r", stdin);
  
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; ++i){
    int u, v; scanf("%d%d", &u, &v);
    --u, --v;
    ed[u][v] = ed[v][u] = true;
  }

  memset(used, -1, sizeof(used));
  setPartition(0);
  dfs(vector<pair<int, int> >());
  
  fac[0] = 1; for(int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i;

  long long ans = 0;
  
  for(set<vector<int> >::iterator it = can.begin(); it != can.end(); ++it){
    int mx = -1;
    for(int i = 0; i < n; ++i)
      mx = max(mx, (*it)[i]);
    if(k >= mx + 1)
      ans += fac[k] / fac[k - (mx + 1)];
  }

  printf("%lld\n", ans);
  return 0;
}