#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		bool zero=0;
		ll neg=0;
		ll tot=0;
		for(ll i=0;i<N;i++){
			ll a;
			cin>>a;
			if(a<0)neg++;
			if(a==0)zero=1;
			tot+=min(abs(a-1),abs(a+1));
		}
		if(zero==1 || neg%2==0)cout<<tot;
		else cout<<tot+2;
		return 0;
}