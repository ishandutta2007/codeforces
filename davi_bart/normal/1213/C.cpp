#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
			ll N,M;
			cin>>N>>M;
			vector<ll> digit;
			digit.push_back(0);
			for(ll i=1;i<10;i++){
				digit.push_back((M*i)%10);
			}
			for(ll i=1;i<digit.size();i++){
				digit[i]+=digit[i-1];
			}
			ll p=N/M/10;
			cout<<digit.back()*p+digit[(N/M)%10]<<'\n';
		}
		return 0;
}