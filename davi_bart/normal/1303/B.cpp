#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
      ll N,a,b;
      cin>>N>>a>>b;
      ll k=N/2+N%2;
      ll tot=(k/a*(a+b))+k%a;
      if(k%a==0)tot-=b;
      tot=max(N,tot);
      cout<<tot<<'\n';
		}
    return 0;
}