#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,a[500003],maxn=-1000000000,minn=1000000000;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	if(n==1){
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<n;i++)ans+=fabs(a[i]);
	for(int i=0;i<n;i++)maxn=max(a[i],maxn),minn=min(a[i],minn);
	if(maxn<0)ans=ans+maxn+maxn;
	if(minn>0)ans=ans-minn-minn;
	cout<<ans;
	return 0;
}