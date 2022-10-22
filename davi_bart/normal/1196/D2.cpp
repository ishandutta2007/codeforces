#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char p[3]={'R','G','B'};
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
      int N,K;
      cin>>N>>K;
      string a;
      cin>>a;
      int mi=1000000;
      for(int j=0;j<3;j++){
        int cambio=0;
        for(int i=0;i<N;i++){
          if(a[i]!=p[(i+j)%3])cambio++;
          if(i<K-1)continue;
          if(i==K-1){
            mi=min(mi,cambio);
            continue;
          }
          if(a[i-K]!=p[(j+i-K)%3])cambio--;
          mi=min(mi,cambio);
        }
      }
      cout<<mi<<endl;
    }
    return 0;
}