#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int N=(int) 4e5+7;
int n;
vector<int> a[N];
vector<pair<int,int>> g[N];
vector<int> path;
map<int, int> gi[N];
bool u[N];
map<int, int> tr;

void dfs(int a){
  while(!g[a].empty()){
    int i=g[a].back().second,b=g[a].back().first;
    g[a].pop_back();
    if(!u[i]){
      u[i]=1;
      dfs(b);
    }
  }
  path.push_back(a);
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
  for(int i=1;i<=n;i++){
    int l;
    cin>>l;
    a[i].resize(l);
    for(auto&x:a[i]){
      cin>>x;
      tr[x]=0;
    }
  }

  int ind=0;
  for(auto &it:tr){
    it.second=++ind;
  }

  for(int i=1;i<=n;i++){
    for(auto&x:a[i]){
      x=tr[x];
    }
  }

  int e=0;

  for(int i=1;i<=n;i++){
    for(auto&x:a[i]){
      g[i].push_back({x+n,++e});
      g[x+n].push_back({i,e});
    }
  }

  for(int i=1;i<=n+ind;i++){
    if((int)g[i].size()%2){
      cout<<"NO\n";
      return 0;
    }
  }


  for(int i=1;i<=n;i++){
    path.clear();
    dfs(i);
    for(int j=0;j<(int)path.size()-1;j++){
      if(path[j]<=n){
        assert(j+1<(int)path.size());
        assert(path[j+1]>n);
        int i=path[j];
        int x=path[j+1]-n;
        gi[i][x]++;
      }
    }
  }

  cout<<"YES\n";
  for(int i=1;i<=n;i++){
    for(auto&x:a[i]){
      if(gi[i][x]){
        cout<<"L";
        gi[i][x]--;
      }else{
        cout<<"R";
      }
    }
    cout<<"\n";
  }
  return 0;
}