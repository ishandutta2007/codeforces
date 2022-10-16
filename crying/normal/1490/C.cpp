#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
ll t,x;
map<ll,ll>f;
int main(){
	cin>>t;
	rep(i,1,10000LL)f[i*i*i]=1LL;
	while(t--){
		cin>>x;
		rep(i,1,10000LL){
			if(i*i*i>=x)break;
			if(f[x-i*i*i])goto END;
		}
		cout<<"NO\n";continue;
		END:cout<<"YES\n";
	}
	return 0;
}