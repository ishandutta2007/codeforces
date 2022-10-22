#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> p;
bool vis[201000];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      p.push_back(a);
    }
    sort(p.begin(),p.end());
    int d=N/2-1;
    int tot=0;
    for(int i=0;i<N;i++){
      if(vis[i])continue;
      int j;
      bool s=0;
      for(j=d+1;j<N;j++){
        if(p[j]-p[i]>=K){
          s=1;
          break;
        }
      }
      if(s==0)break;
      tot++;
      d=j;
      vis[i]=1;
      vis[d]=1;
    }
    cout<<tot;
    return 0;
}