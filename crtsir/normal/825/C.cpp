#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1003],cnt,ans;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		while(a[i]>k*2)k*=2,ans++;
		k=max(k,a[i]);
	}
	cout<<ans;
}