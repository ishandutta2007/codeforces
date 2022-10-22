#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      ll a,b,c;
      cin>>a>>b>>c;
      ll m=max(max(a,b),c);
      ll tot=a+b+c;
      if(m>(tot+1)/2)cout<<"No"<<'\n';
      else cout<<"Yes"<<'\n';
    }
    return 0;
}