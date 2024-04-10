#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
ll n;
int m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	while(m--){
		ll x,y;cin>>x>>y;
		if((x&1)^(y&1)){
			ll ans=(n*n+1)/2+((x-1)/2)*n;
			if(x&1)
				cout<<ans+y/2<<endl;
			else cout<<ans+n/2+(y+1)/2<<endl;
		}
		else{
			ll ans=((x-1)/2)*n;
			if(x&1)
				cout<<ans+(y+1)/2<<endl;
			else cout<<ans+(n+1)/2+y/2<<endl;
		}
	}
	return 0;
}