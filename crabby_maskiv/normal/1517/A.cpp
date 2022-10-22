#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		ll x;cin>>x;
		if(x%2050){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		x/=2050;
		while(x){
			ans+=x%10;
			x/=10;
		}
		cout<<ans<<endl;
	}
	return 0;
}