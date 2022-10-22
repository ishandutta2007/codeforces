#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[1010];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      p[a]++;
    }
    int coppie=N/2+N%2;
    int soli=0;
    for(int i=0;i<=K;i++){
      coppie-=p[i]/2;
      soli+=p[i]%2;
    }
    soli-=coppie;
    cout<<N-soli;
    return 0;
}