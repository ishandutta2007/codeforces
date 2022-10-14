#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p[1926]={1},sum[1926],ans[1926],siz;
signed main()
{
	for(int i=1;i<63;i++) p[i]=p[i-1]<<1;
	scanf("%lld%lld",&a,&b);
	for(int i=62;i>=0;i--) if(p[i]&a) sum[i]=1; else a=a;
	b-=a;
	if(b<0||(b&1)) return 0&puts("-1");
	int c;
	for(int i=62;i>=0;i--) c=b/p[i]/2*2,sum[i]+=c,b-=p[i]*c,siz=max(siz,sum[i]); 
	printf("%lld\n",siz);
	for(int i=1;i<=siz;i++)
	{
		int t=0;
		for(int i=62;i>=0;i--) if(sum[i])sum[i]--,t+=p[i];
		printf("%lld ",t);
	}
	return 0; 
}