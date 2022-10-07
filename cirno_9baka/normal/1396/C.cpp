#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353;
int n,i,t,r1,r2,r3,d;
int a[N];
long long f[N][2];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d %d %d",&n,&r1,&r2,&r3,&d);
	f[0][1]=100000000000000000ll;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		f[i][0]=min(f[i-1][0]+1ll*r1*a[i]+r3,f[i-1][1]+min(1ll*(a[i]+2)*r1,1ll*r1+r2));
		f[i][1]=f[i-1][0]+min({1ll*r1+r2,1ll*r1*(a[i]+2),1ll*r1*a[i]+r3})+d*2;
	}
	cout<<min(f[n-1][1]-d+1ll*r1*a[n]+r3,min(f[n][0],f[n][1]))+1ll*d*(n-1);
}