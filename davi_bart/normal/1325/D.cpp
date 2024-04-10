#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b;
    cin>>a>>b;
    if(a>b){
      cout<<-1;
      return 0;
    }
    if(a==b){
      if(a==0){
        cout<<0;
        return 0;
      }
      cout<<1<<endl<<a;
      return 0;
    }
    b-=a;
    if(b%2){
      cout<<-1;
      return 0;
    }
    b/=2;
    vector<ll> k;
    if(a!=0)k.push_back(a);
    k.push_back(b);
    if((a^b)==(a+b) && a!=0)k[0]+=b;
    else k.push_back(b);
    cout<<k.size()<<endl;
    for(ll i=0;i<k.size();i++)cout<<k[i]<<" ";
    return 0;
}