#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pos[200010];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<int> v(N);
    set<int> p[M];
    int tot=N-1;
    for(int i=0;i<M;i++){
        pos[i]=i;
    }
    for(int i=0;i<N;i++){
        cin>>v[i];
        v[i]--;
        p[v[i]].insert(i);
    }
    for(int i=1;i<N;i++){
      if(v[i]==v[i-1])tot--;
    }
    M--;
    cout<<tot<<'\n';
    while(M--){
      int a,b;
      cin>>a>>b;
      a--;b--;
      while(pos[a]!=a)a=pos[a];
      while(pos[b]!=b)b=pos[b];
      if(p[a].size()>p[b].size())swap(a,b);
      for(int x:p[a]){
        p[b].insert(x);
        if(x<N-1 && v[x]==v[x+1])tot++;
        v[x]=b;
        if(x>0 && v[x]==v[x-1])tot--;
        if(x<N-1 && v[x]==v[x+1])tot--;
      }
      p[a].clear();
      pos[a]=b;
      cout<<tot<<'\n';
    }
}