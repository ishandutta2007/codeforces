#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> p;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ll N;
    cin>>N;
    ll s=0;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      p.push_back(a);
      s+=a;
    }
    sort(p.begin(),p.end(),greater<ll>());
    if(p[0]<=s/2 && s%2==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}