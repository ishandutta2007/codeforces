#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int>v[500010];
bool vis[500010];
int sol[500010];
vector<vector<int> >gruppi;
void dfs(int pos){
  vis[pos]=1;
  for(int i=0;i<v[pos].size();i++){
    if(vis[v[pos][i]]==0){
      gruppi.back().push_back(v[pos][i]);
      dfs(v[pos][i]);
    }
  }
}
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a;
    cin>>a;
    if(a==0)continue;
    int prec,curr;
    cin>>prec;
    for(int j=1;j<a;j++){
      cin>>curr;
      v[curr].push_back(prec);
      v[prec].push_back(curr);
      prec=curr;
    }
  }
    for(int i=1;i<=N;i++){
      if(vis[i])continue;
      gruppi.push_back(vector<int>());
      gruppi.back().push_back(i);
      dfs(i);
    }
    for(int i=0;i<gruppi.size();i++){
      for(int j=0;j<gruppi[i].size();j++){
        sol[gruppi[i][j]]=gruppi[i].size();
      }
    }
  for(int i=1;i<=N;i++){
    cout<<sol[i]<<" ";
  }
  cout.flush();
	return 0;
}