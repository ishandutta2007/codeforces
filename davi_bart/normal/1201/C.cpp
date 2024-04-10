#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> p;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ll N,K;
    cin>>N>>K;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      p.push_back(a);
    }
    sort(p.begin(),p.end());
    p.push_back(100000000000);
    ll sol=p[N/2];
    ll ug=0;
    while(K>0){
      ll succ=p[N/2+ug];
      if((succ-sol)*ug<=K){
        K-=(succ-sol)*ug;
        ug++;
        sol=succ;
      }else{
        sol+=K/ug;
        break;
      }
    }
    cout<<sol;
    return 0;
}