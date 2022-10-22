#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int nodi[201000];// 1 riceve
vector<int> v[201000];
vector<pair<int,int> > edge;
vector<bool>sol;
bool vis[201000];
void dfs(int pos,bool dir){
  nodi[pos]=dir;
  vis[pos]=1;
  for(int i=0;i<v[pos].size();i++){
    if(vis[v[pos][i]]==0)dfs(v[pos][i],!dir);
  }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      edge.push_back({a,b});
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(1,0);
    for(int i=0;i<M;i++){
      if(nodi[edge[i].first]==nodi[edge[i].second]){
        cout<<"NO";
        return 0;
      }
      sol.push_back(nodi[edge[i].first]);
    }
    cout<<"YES"<<endl;
    for(int i=0;i<sol.size();i++){
        cout<<sol[i];
    }
    return 0;
}