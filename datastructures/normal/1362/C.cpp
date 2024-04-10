#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,n;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for (int i=0;i<=60;i++)
			ans+=n/(1ll<<i);
		cout<<ans<<endl;
	}
	return 0;
}