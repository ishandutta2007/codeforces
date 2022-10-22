#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N,M,rad;
vector<int> v[100010];
vector<int> vis(100010,-1);
int k=0;
vector<int> sol;
void stampa(){
  cout<<2<<'\n'<<sol.size()<<'\n';
  for(int i=0;i<sol.size();i++)cout<<sol[i]+1<<" ";
  exit(0);
}
int dfs(int pos){
  if(vis[pos]!=-1){
    if(k-vis[pos]>=rad){
      sol.push_back(pos);
      return vis[pos];
    }
    return -1;
  }
  vis[pos]=k;
  k++;
  for(int i=0;i<v[pos].size();i++){
    int g=dfs(v[pos][i]);
    k=vis[pos]+1;
    if(g==-1)continue;
    if(g==vis[pos]){
      stampa();
    }
    sol.push_back(pos);
    return g;
  }
  return -1;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>N>>M;
		rad=(int)ceil(sqrt(N));
		for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      v[a].push_back(b);
      v[b].push_back(a);
		}
		dfs(0);
		vector<int> p;
		for(int i=0;i<N;i++)p.push_back(i);
		while(1){
      shuffle(p.begin(),p.end(),rng);
      sol.clear();
      fill(vis.begin(),vis.end(),0);
      for(int i=0;i<p.size();i++){
        if(vis[p[i]]==0){
          sol.push_back(p[i]);
          vis[p[i]]=1;
          for(int j=0;j<v[p[i]].size();j++)vis[v[p[i]][j]]=1;
        }
        if(sol.size()==rad){
          cout<<1<<'\n';
          for(int j=0;j<sol.size();j++)cout<<sol[j]+1<<" ";
          exit(0);
        }
      }
		}
    return 0;
}