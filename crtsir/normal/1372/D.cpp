#include<bits/stdc++.h>
using namespace std;
int n,a[200003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	long long ans=0,cnt=0;
	for(int i=0;i<n;i+=2)cnt+=a[i];
	int i=n-1,cntt=0;
	for(;cntt<n;cntt++){
		ans=max(ans,cnt);
		cnt+=a[(i+2)%n];cnt-=a[(i+1)%n];i=(i+2)%n; 
	}
	cout<<ans;
}