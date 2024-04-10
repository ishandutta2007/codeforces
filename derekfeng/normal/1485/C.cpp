#include <bits/stdc++.h>
using namespace std;
int T,X,Y;
int main(){
	cin>>T;
	while(T--){
		cin>>X>>Y;
		int mx=floor(sqrt(X));
		long long ans=0;
		for(int i=1;i<=mx;i++)ans+=max(0,min(Y,X/i-1)-i);
		cout<<ans<<'\n';
	}
}