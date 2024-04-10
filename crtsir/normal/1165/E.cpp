#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[200006],b[200006],c[200006],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++)
		a[i]=a[i]*(i+1)*(n-i);
	sort(a,a+n);sort(b,b+n);
	for(int i=0;i<n;i++)
		ans=(ans+a[i]%mod*b[n-1-i]%mod)%mod;
	cout<<ans;
}