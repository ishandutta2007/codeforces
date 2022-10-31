#include<bits/stdc++.h>
#define int long long 
const int mod=998244353;
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
main(){
	ios::sync_with_stdio(0);
	int n;cin>>n;
	vector<int>a(n+1),fa(n+1),f(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)cin>>fa[i];
	for(int i=n;i;i--)a[fa[i]]+=a[i];
	for(int i=1;i<=n;i++)if(a[1]/gcd(a[1],a[i])<=n)
		++f[a[1]/gcd(a[1],a[i])];
	for(int i=n;i;i--)
		for(int j=i+i;j<=n;j+=i)
			f[j]+=f[i];
	int ans=1;
	for(int i=n;i>1;i--)if(f[i]=f[i]==i){
		for(int j=i+i;j<=n;j+=i)
			f[i]+=f[j];
		ans+=f[i]%mod;
	}
	cout<<ans%mod<<endl;
}