#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,base,pd[2000];
int main()
{
	n=read(),K=read();
	if(K==1)
	{
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
			{
				char s[5];
				printf("? %d\n",i);
				fflush(stdout);
				scanf("%s",s);
				printf("? %d\n",j);
				fflush(stdout);
				scanf("%s",s);
				puts("R");
				fflush(stdout);
				if(s[0]=='Y') pd[j]=1;
			}
		int ans=0;
		for(int i=1;i<=n;++i) if(!pd[i]) ++ans;
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	base=K/2;
	for(int p=1;p<n/base;++p)
	{
		for(int st=1;st<=p && st+p<=n/base;++st)
		{
			for(int i=st;i<=n/base;i+=p)
			{
				for(int j=(i-1)*base+1;j<=i*base;++j)
				{
					printf("? %d\n",j);
					fflush(stdout);
					char s[5]; scanf("%s",s);
					if(s[0]=='Y') pd[j]=1;
				}
			}
			puts("R");
			fflush(stdout);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) if(!pd[i]) ++ans;
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}