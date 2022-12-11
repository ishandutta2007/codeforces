#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
mt19937 myrand(time(0)+(unsigned long long)(new char));
const int mod=998244353;
int sed;
char s[1000010],a[2000020];
int T,n,lmax[2000020],rmax[2000020],has1[2000020],has2[2000020],ans,r[2000020],ansp,f;
int main()
{
	sed=myrand()%(mod-200)+200;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)a[i*2]=s[i],a[i*2-1]='#';a[0]=-1;a[2*n+1]='#';a[2*n+2]=-2;
		int maxr=0,mid=0;
		for(int i=1;i<=2*n;++i)
		{
			if(i>maxr)r[i]=1;
			else r[i]=min(r[(mid<<1)-i],maxr-i);
			while(a[i+r[i]]==a[i-r[i]])++r[i];
			if(i+r[i]>maxr)
			{
				maxr=i+r[i];
				mid=i;	
			}
			if(i>=n+1)lmax[i+r[i]-1]=max(lmax[i+r[i]-1],r[i]-1);
			if(i<=n+1)rmax[i-r[i]+1]=max(rmax[i-r[i]+1],r[i]-1);
		}
		for(int i=2*n+1;i>=1;--i)lmax[i]=max(lmax[i],lmax[i+1]-1);
		for(int i=1;i<=2*n+1;++i)rmax[i]=max(rmax[i],rmax[i-1]-1);
	//	for(int i=1;i<=2*n;++i)putchar(a[i]);putchar('\n');
	//	for(int i=1;i<=2*n+1;++i)printf("%d ",lmax[i]);printf("\n");
	//	for(int i=1;i<=2*n+1;++i)printf("%d ",rmax[i]);printf("\n");
		for(int i=1;i<=n;++i)has1[i]=(1ll*has1[i-1]*sed+s[i])%mod;
		has2[n+1]=0;for(int i=n;i;--i)has2[i]=(1ll*has2[i+1]*sed+s[i])%mod;
		ans=0;ansp=0;
		for(int i=0;i*2<=n;++i)
			if(has1[i]==has2[n-i+1])
			{
				if(i*2+rmax[i*2+1]>ans)
				{
					ans=i*2+rmax[i*2+1];
					ansp=i,f=0;
				}
	//			printf("%d ",lmax[(n-i)*2+1]);
				if(i*2+lmax[(n-i)*2+1]>ans)
				{
					ans=i*2+lmax[(n-i)*2+1];
					ansp=i,f=1;
				}
			}
	//	printf("%d\n",ans);
		for(int i=1;i<=ansp;++i)printf("%c",s[i]);
		if(f==0)for(int i=ansp+1;i<=ans-ansp;++i)printf("%c",s[i]);
		else for(int i=n+ansp-ans+1;i<=n-ansp;++i)printf("%c",s[i]);
		for(int i=n-ansp+1;i<=n;++i)printf("%c",s[i]);
		printf("\n");
		for(int i=1;i<=2*n+1;++i)lmax[i]=rmax[i]=r[i]=0;
	//	printf("%d %d %d %d\n",lmax[0],rmax[0],lmax[2*n+1],rmax[2*n+2]);
	}
	return 0;
}