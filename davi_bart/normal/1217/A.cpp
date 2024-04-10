#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ll T;
		cin>>T;
		while(T--){
			ll a,b,c;
			cin>>a>>b>>c;
			ll diff=a-b;
			if(diff>0){
				if(diff>c)cout<<c+1<<'\n';
				else if(diff==c)cout<<c<<'\n';
				else cout<<diff+1+(c-diff-1)/2<<'\n';
			}else	if(diff==0)cout<<(c+1)/2<<'\n';
			else{
				c+=diff;
				if(c<=0)cout<<0<<'\n';
				else cout<<(c+1)/2<<'\n';
			}
		}
		return 0;
}