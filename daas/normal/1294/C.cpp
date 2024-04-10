#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,num[31622],tot,a[31622][2],cnt;
bool pd[31623];
int main()
{
	for(register int i=2;i<=31622;++i)
	{
		if(!pd[i])
			num[++tot]=i;
		for(register int j=1;j<=tot && num[j]*i<=31622;++j)
		{
			pd[num[j]*i]=1;
			if(i%num[j]==0)
				break;
		}
	}
	T=read();
	while(T--)
	{
		cnt=0;
		int n=read(),mem=1;
		for(register int i=1;i<=tot;++i)
			if(n%num[i]==0)
			{
				a[++cnt][0]=num[i];
				a[cnt][1]=0;
				for(register int j=n;j%num[i]==0;j/=num[i])
					++a[cnt][1],mem*=num[i];
			}
		if(n!=mem)
			a[++cnt][0]=n/mem,a[cnt][1]=1;
		if(cnt>=3)
		{
			puts("YES");
			printf("%d %d %d\n",a[1][0],a[2][0],n/a[1][0]/a[2][0]);
			continue;
		}
		if(cnt==2 && a[1][1]+a[2][1]>=4)
		{
			puts("YES");
			printf("%d %d %d\n",a[1][0],a[2][0],n/a[1][0]/a[2][0]);
			continue;
		}
		if(cnt==1 && a[1][1]>=6)
		{
			puts("YES");
			printf("%d %d %d\n",a[1][0],a[1][0]*a[1][0],n/a[1][0]/a[1][0]/a[1][0]);
			continue;
		}
		puts("NO");
	}
	return 0;
}