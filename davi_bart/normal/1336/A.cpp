#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
vector<int> v[200010];
vector<int> deep(200010);
vector<int> sotto(200010);
int dfs(int pos,int d,int prec){
  deep[pos]=d;
  for(int i=0;i<v[pos].size();i++){
      if(v[pos][i]==prec)continue;
    sotto[pos]+=dfs(v[pos][i],d+1,pos);
  }
  return sotto[pos]+1;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("output.txt","w",stdout);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(0,0,-1);
    vector<int> p;
    for(int i=0;i<N;i++){
      p.push_back(deep[i]-sotto[i]);
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    ll tot=0;
    for(int i=0;i<K;i++)tot+=(ll)p[i];
    cout<<tot;
    return 0;
}