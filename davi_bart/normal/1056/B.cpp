#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    int tot=0;
    for(int i=1;i<=M;i++){
      for(int j=1;j<=M;j++){
        int t=i*i+j*j;
        if(t%M==0){
          tot+=(N/M+(N%M>=i))*(N/M+(N%M>=j));
        }
      }
    }
    cout<<tot;
}