#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,cnta[4],cntb[4],dy[2][2],ans[4040],k;
char a[4040],b[4040];
int main()
{
	dy[0][0]=0,dy[0][1]=1,dy[1][0]=2,dy[1][1]=3;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s %s",a+1,b+1);
		n=strlen(a+1);k=0;
		for(int i=1;i<=n;++i)a[i]-='0',b[i]-='0';
		cnta[0]=cnta[1]=cnta[2]=cnta[3]=0;
		for(int i=2;i<=n;i+=2)++cnta[dy[a[i-1]][a[i]]];
		cntb[0]=cntb[1]=cntb[2]=cntb[3]=0;
		for(int i=2;i<=n;i+=2)++cntb[dy[b[i-1]][b[i]]];
		if(cnta[0]!=cntb[0]||cnta[3]!=cntb[3]){printf("-1\n");continue;}
		if(abs(cnta[1]-cnta[2])>=abs(cntb[1]-cntb[2]))
		{
		//	printf("1:\n");
			if(cnta[1]!=cntb[2])
			{
		//		printf("!\n");
				int now=0;
				for(int i=2;i<=n;i+=2)
				{
					if(dy[a[i-1]][a[i]]==1)++now;
					if(dy[a[i-1]][a[i]]==2)--now;
					if(cnta[1]-cnta[2]-2*now==cntb[2]-cntb[1])
					{
						reverse(a+1,a+i+1);
		//				printf("%d\n",i);
						ans[++k]=i;
						break;
					}
				}					
			}
		//	for(int j=1;j<=n;++j)printf("%d",a[j]);printf("\n");
			for(int i=2;i<=n;i+=2)
			{
				int p,c=dy[b[n-i+2]][b[n-i+1]];
				for(int j=i;j<=n;j+=2)
					if(dy[a[j-1]][a[j]]==c){p=j;break;}
		//		printf("%d %d\n",i,p);
				reverse(a+1,a+1+p-2),ans[++k]=p-2;
		//		for(int j=1;j<=n;++j)printf("%d",a[j]);printf("\n");
				reverse(a+1,a+1+p),ans[++k]=p;
		//		for(int j=1;j<=n;++j)printf("%d",a[j]);printf("\n");
			}
			int cnt=0;
			for(int i=1;i<=k;++i)
				if(ans[i])
				{
					if(cnt&&ans[i]==ans[cnt])--cnt;
					else ans[++cnt]=ans[i];
				}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;++i)printf("%d ",ans[i]);printf("\n");
		}
		else
		{
		//	printf("2:\n");
			int now=0;
			for(int i=2;i<=n;i+=2)
			{
				if(dy[b[i-1]][b[i]]==1)--now;
				if(dy[b[i-1]][b[i]]==2)++now;
				if(cnta[1]-cnta[2]==cntb[2]-cntb[1]-2*now)
				{
					reverse(b+1,b+i+1);
					ans[++k]=i;break;
				}
			}
			for(int i=2;i<=n;i+=2)
			{
				int p,c=dy[a[n-i+2]][a[n-i+1]];
				for(int j=i;j<=n;j+=2)
					if(dy[b[j-1]][b[j]]==c){p=j;break;}
				reverse(b+1,b+1+p-2),ans[++k]=p-2;
				reverse(b+1,b+1+p),ans[++k]=p;
			}
			reverse(ans+1,ans+1+k);
			int cnt=0;
			for(int i=1;i<=k;++i)
				if(ans[i])
				{
					if(cnt&&ans[i]==ans[cnt])--cnt;
					else ans[++cnt]=ans[i];
				}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;++i)printf("%d ",ans[i]);printf("\n");
		}
	}
	return 0;
}