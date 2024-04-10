#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 500000
char g[MN+5];
int n,a,b,t,ans,f[MN+5];
void solve()
{
	int i,j,s;
	for(i=n;i--;)f[i]=f[i+1]+a+b*(g[i]=='w')+1;
	for(i=j=s=0;i<n;++i,s+=a)
	{
		s+=b*(g[i]=='w')+1;
		if(s>t)break;
		ans=max(ans,i+1);
		if(s+i*a<=t)
		{
			while(j<=i||s+f[j]+i*a>t)++j;
			ans=max(ans,i+1+n-j);
		}
	}
}
int main()
{
	scanf("%d%d%d%d%s",&n,&a,&b,&t,g);
	solve();
	for(int i=1;i<n-i;++i)swap(g[i],g[n-i]);
	solve();
	printf("%d",ans);
}