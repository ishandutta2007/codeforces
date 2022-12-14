#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
stack<ll>s;
ll t,n,k,a[200005],b[200005];
inline ll read()
{
	ll zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	t=read();
	while(t--)
	{
		n=read(),k=read()+1;
		for(re i=1;i<=n;i++) a[i]=read();
		re maxn=1e9,ans;
		for(re i=1;i<=n-k+1;i++)
		{
			re j=i+k-1,mid=(a[i]+a[j])>>1;
			if(a[j]-a[i]<maxn) maxn=a[j]-a[i],ans=mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}