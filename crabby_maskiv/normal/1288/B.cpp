#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		ll ans=0,x=10;
		while(x-1<=m){
			ans+=n;
			x=x*10;
		}
		cout<<ans<<endl;
	}
	return 0;
}