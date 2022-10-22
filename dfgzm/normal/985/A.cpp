#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,a[9090];
int main(){
	cin>>n;
	for(i=1;i<=n/2;i++)cin>>a[i];
	sort(a+1,a+1+n/2);
	int ans=0,sum=0;
	for(i=1;i<=n/2;i++)sum+=abs(a[i]-(2*i-1));
	for(i=1;i<=n/2;i++)ans+=abs(a[i]-(2*i));
	cout<<min(ans,sum)<<endl;
	return 0;
}