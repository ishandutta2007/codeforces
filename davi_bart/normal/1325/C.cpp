#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > v[100010];
vector<int> sol(100010,0);
int k=0;
void dfs(int pos,int prec){
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i].first==prec)continue;
    sol[v[pos][i].second]=k;
    k++;
  }
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i].first==prec)continue;
    dfs(v[pos][i].first,pos);
  }
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      v[a].push_back({b,i});
      v[b].push_back({a,i});
    }
    int r=0;
    for(int i=0;i<N;i++){
        if(v[i].size()>2)r=i;
    }
    dfs(r,-1);
    for(int i=0;i<N-1;i++){
      cout<<sol[i]<<'\n';
    }
    return 0;
}