#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M,K;
    cin>>N>>M>>K;
    int mi=1000000000,ma=0;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(a<mi)mi=a;
    }
    int c=K/mi;
    for(int i=0;i<M;i++){
      int a;
      cin>>a;
      if(a>ma)ma=a;
    }
    if(ma<mi){
      cout<<K;
      return 0;
    }
    K=K%mi;
    cout<<K+c*ma;
    return 0;
}