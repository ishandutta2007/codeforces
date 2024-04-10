#pragma GCC optimize("O3")
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> v[100005];
int mod=1e9+7;
bool vis[100005];
long long int pot(int base,int esp){
  long long int val=1;
  for(int i=0;i<esp;i++){
    val*=base;
    val%=mod;
  }
  return val;
}
long long int dfs(int pos,int prec){
    vis[pos]=1;
  long long int s=1;
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i]!=prec)s+=dfs(v[pos][i],pos);
  }
  return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N-1;i++){
      int a,b,c;
      cin>>a>>b>>c;
      if(c==0){
        v[a].push_back(b);
        v[b].push_back(a);
      }
    }
    long long int tot=0;
    for(int i=1;i<=N;i++){
      int o=0;
      if(vis[i]==0)o=dfs(i,0);
      tot+=pot(o,K);
      tot%=mod;
    }
    long long int f=pot(N,K);
    long long int sol=(f-tot)+mod;
    cout<<sol%mod;
    return 0;
}