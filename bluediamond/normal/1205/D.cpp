#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

const int N=1000+7;
int n;
int want;
vector<int> g[N];
int sub[N];

void build(int a,int p=-1){
  sub[a]=1;
  for(auto&b:g[a]){
    if(b!=p){
      build(b,a);
      sub[a]+=sub[b];
    }
  }
}

int current,la[N];
vector<vector<int>> sol;

void dfs(int a,int p){
  sol.push_back({p,a,current-la[p]});
  la[a]=current;
  current++;
  for(auto&b:g[a]){
    if(b==p) continue;
    dfs(b,a);
  }
}

void solveprint(int root,vector<vector<int>> guys,vector<int> cur){
  current=1;
  for(auto&it:guys[0]){
    dfs(it,root);
  }
  for(auto&x:sol){
    x[2]*=(cur[1]+1);
  }
  current=1;
  for(auto&it:guys[1]){
    dfs(it,root);
  }
  assert((int)sol.size()==n-1);
  for(auto&x:sol){
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
  }
  exit(0);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;
  want=(2*n*n)/9;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }


  for(int root=1;root<=n;root++){
    build(root,-1);
    vector<pair<int, int>> szs;
    for(auto&i:g[root]){
      szs.push_back({sub[i],i});
    }
    sort(szs.rbegin(),szs.rend());
    vector<vector<int>> guys(2);
    vector<int> cur(2,0);
    
    for(auto&it:szs){
      int sz=it.first,i=it.second;
      int delta0=abs((cur[0]+sz)-cur[1]);
      int delta1=abs(cur[0]-(cur[1]+sz));
      if(delta0<delta1){
        cur[0]+=sz;
        guys[0].push_back(i);
      }else{
        cur[1]+=sz;
        guys[1].push_back(i);
      }
    }
    if((cur[0]+1)*(cur[1]+1)-1>=want){
      solveprint(root,guys,cur);
    }
  }
  assert(0);




  return 0;
}