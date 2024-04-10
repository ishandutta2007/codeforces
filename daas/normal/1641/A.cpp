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
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,x,a[MAXN],num[MAXN],cnt,ton[MAXN],ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),x=read();
		for(int i=1;i<=n;++i) num[i]=a[i]=read();
		sort(num+1,num+n+1);
		cnt=unique(num+1,num+n+1)-num-1;
		for(int i=1;i<=n;++i) ++ton[lower_bound(num+1,num+cnt+1,a[i])-num];
		ans=0;
		for(int i=1;i<=cnt;++i)
		{
			if((ll)num[i]*x<=num[cnt])
			{
				int id=lower_bound(num+1,num+cnt+1,num[i]*x)-num;
				if(num[id]==num[i]*x)
				{
					int minn=min(ton[id],ton[i]);
					ton[i]-=minn;
					ton[id]-=minn;
				}
			}
			ans+=ton[i];
			ton[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!