#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define mod 998244353
#define int unsigned long long
using namespace std;
int ans;
int n,k[1000005],sum[1000005],book[1000005];
vector<int> c[1000005];
inline int pw(int a,int p){
	if (p<0)return 0;
	if (p==0)return 1;
	if (p==1)return a%mod;
	a%=mod;
	int t=pw(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&k[i]);
		sum[i]=sum[i-1]+k[i];
		for (int j=1;j<=k[i];j++){
			int x;
			scanf("%I64d",&x);
			c[i].push_back(x);
			book[x]++;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<k[i];j++)
			ans=(ans+pw(n,mod-2)%mod*pw(n,mod-2)%mod*pw(k[i],mod-2)%mod*book[c[i][j]]%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}