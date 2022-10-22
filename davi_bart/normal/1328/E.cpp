#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v[200010];
int d[200010];
int lca[20][200010];
vector<pair<int,int> >k;
void dfs(int pos,int h,int prec){
  d[pos]=h;
  lca[0][pos]=prec;
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i]==prec)continue;
    dfs(v[pos][i],h+1,pos);
  }
}
int dist(int a,int b){
  if(d[a]<d[b])swap(a,b);
  int q=20;
  while(d[a]!=d[b]){
    if((1<<q)<=(d[a]-d[b]))a=lca[q][a];
    q--;
  }
  if(a==b)return 0;
  if(lca[0][a]==lca[0][b])return 0;
  return 1;

}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(0,0,-1);
    for(int i=1;i<20;i++){
      for(int j=0;j<N;j++){
        lca[i][j]=lca[i-1][lca[i-1][j]];
      }
    }
    for(int i=0;i<Q;i++){
      int a;
      cin>>a;
      k.clear();
      for(int j=0;j<a;j++){
        int g;
        cin>>g;
        g--;
        k.push_back({d[g],g});
      }
      sort(k.begin(),k.end());
      bool perso=0;
      for(int i=1;i<k.size();i++){
       // cout<<k[i].second<<endl;
        if(dist(k[i-1].second,k[i].second)){
          perso=1;break;
        }
      }
      if(perso)cout<<"NO"<<'\n';
      else cout<<"YES"<<'\n';
    }
    return 0;
}