#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;
mt19937 myrand(time(0)+(unsigned long long)(new char));
int T,n,k;
int st[1010],tp,a[1010],cnt;
char ret[100];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		int p=myrand()%n+1;;
		for(int i=1;i<=10;++i)
		{
			int x=myrand()%n+1;
			while(x==p)x=myrand()%n+1;
			printf("? 1 1\n%d\n%d\n",p,x);fflush(stdout);
			scanf("%s",ret);
			if(ret[0]=='S')p=x;
		}
		st[tp=1]=p;
		cnt=0;
		for(int i=1;i<=n;++i)if(i!=p)a[++cnt]=i;
		int pos=0;
		for(int i=0;;++i)
		{
			if(pos+(1<<i)<cnt)
			{
				printf("? %d %d\n",tp,tp);
				for(int j=1;j<=tp;++j)printf("%d ",st[j]);printf("\n");
				for(int j=pos+1;j<=pos+tp;++j)printf("%d ",a[j]);printf("\n");
				fflush(stdout);
				scanf("%s",ret);
				if(ret[0]=='E')
				{
					for(int j=pos+1;j<=pos+(1<<i);++j)st[++tp]=a[j];
					pos+=1<<i;
				}
				else
				{
					for(int t=i-1;~t;--t)
					{
						printf("? %d %d\n",1<<t,1<<t);
						for(int j=1;j<=1<<t;++j)printf("%d ",st[j]);printf("\n");
						for(int j=1;j<=1<<t;++j)printf("%d ",a[pos+j]);printf("\n");
						fflush(stdout);
						scanf("%s",ret);
						if(ret[0]=='E')pos+=1<<t;
					}
					break;
				}
			}
			else
			{
				for(int t=i;~t;--t)
				{
					if(pos+(1<<t)>cnt)continue;
					printf("? %d %d\n",1<<t,1<<t);
					for(int j=1;j<=1<<t;++j)printf("%d ",st[j]);printf("\n");
					for(int j=1;j<=1<<t;++j)printf("%d ",a[pos+j]);printf("\n");
					fflush(stdout);
					scanf("%s",ret);
					if(ret[0]=='E')pos+=1<<t;
				}
				break;
			}
		}
		printf("! %d\n",a[pos+1]);fflush(stdout);
	}
	return 0;
}