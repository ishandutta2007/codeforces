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
int T,ton[200010],ans[200010];
int main()
{
	T=read();
	while(T--)
	{
		int A=read(),B=read(),n=A+B;
		int C=A-B;
		int C1=n%2;
		int C2=-C1;
		memset(ton,0,sizeof(ton));
		ans[0]=0;
		if(abs(C-C1)%2==0)
		{
			int vd=n/2+n%2,vp=n/2;
			if(C1<C)
			{
				vp-=(C-C1)/2;
				for(int i=(C-C1)/2;i<=n && vd>=0 && vp>=0;i+=2,--vd,--vp) ton[i]=1;
			}
			else
			{
				vd-=(C1-C)/2;
				for(int i=(C1-C)/2;i<=n && vd>=0 && vp>=0;i+=2,--vd,--vp) ton[i]=1;
			}
		}
		if(abs(C-C2)%2==0)
		{
			int vd=n/2,vp=n/2+n%2;
			if(C2<C)
			{
				vp-=(C-C2)/2;
				for(int i=(C-C2)/2;i<=n && vd>=0 && vp>=0;i+=2,--vd,--vp) ton[i]=1;
			}
			else
			{
				vd-=(C2-C)/2;
				for(int i=(C2-C)/2;i<=n && vd>=0 && vp>=0;i+=2,--vd,--vp) ton[i]=1;
			}
		}
		for(int i=0;i<=n;++i) if(ton[i]) ans[++ans[0]]=i;
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!