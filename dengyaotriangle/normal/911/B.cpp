#include<bits/stdc++.h>

using namespace std;

int main(){
	long long ans=1;
	long long n,a,b;
	cin>>n>>a>>b;
	for(int i=0;i<=n;i++){
		long long ca=0,cb=0;
		if(i==0&&a!=0) continue;
		if(i==n&&b!=0) continue;
		if(i!=0) ca=a/i;
		if(i!=n) cb=b/(n-i);
		ans=max(ans,min(ca,cb));
	}
	cout<<ans;
	return 0;
}