#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		ll g;
		cin>>g;
		for(ll i=1;i<N;i++){
			ll a;
			cin>>a;
			g=__gcd(g,a);
		}
		ll tot=0;
		for(ll i=1;i<=sqrt(g);i++){
			if(g%i==0)tot+=2;
			if(i==sqrt(g))tot--;
		}
		cout<<tot<<endl;
		return 0;
}