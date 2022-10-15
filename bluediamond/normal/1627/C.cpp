#include <bits/stdc++.h>

using namespace std;

const int N=(int)1e5+7;
int n,s[N],ite;
pair<int,int>e[N];
vector<pair<int,int>>g[N];
bool ve[N];

void dfs(int a){
  if(ite==2)ite=3;
  else ite=2;
  ve[a]=1;
  for (auto &it:g[a]){
    int b=it.first,i=it.second;
    if(!ve[b]){
      s[i]=ite;
      dfs(b);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int tt;cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    ite=2;
    for (int i=1;i<=n;i++)g[i].clear(),e[i]={0,0},s[i]=-1,ve[i]=0;
    for (int i=1;i<n;i++){
      int x,y;
      cin>>x>>y;
      e[i]={x,y};
      g[x].push_back({y,i});
      g[y].push_back({x,i});
    }
    int dm=0;
    for (int i=1;i<=n;i++){
      dm=max(dm,(int)g[i].size());
    }
    if(dm>2){
      cout<<"-1\n";
      continue;
    }
    int v=1;
    while((int)g[v].size()==2)v++;
    assert((int)g[v].size()==1&&v<=n);
    dfs(v);
    for (int i=1;i<n;i++)cout<<s[i]<<" ";
    cout<<"\n";
  }
  return 0;
}