#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define mod 1000000007 
using namespace std;
int f[1000005],c[1000005],n,a[100005];
inline void update(int now){
	for (int i=1;i*i<=now;i++){
		if (now%i!=0)continue;
		c[i]=(f[i]+f[i-1])%mod;
		if (i!=now/i){
			c[now/i]=(f[now/i]+f[now/i-1])%mod;
		}
	}
	for (int i=1;i*i<=now;i++){
		if (now%i!=0)continue;
		f[i]=c[i];
		if (i!=now/i){
			f[now/i]=c[now/i];
		}
	}
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	f[0]=1;
	for (int i=1;i<=n;i++){
		update(a[i]);
	}
	int ans=0;
	for (int i=1;i<=1000000;i++)ans+=f[i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}