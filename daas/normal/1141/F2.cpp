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
int a[1501],ans,pre[2550001],road,n,num;
struct sb
{
	int l,r,value;
}t[2250001];
inline int cmp(sb x,sb y)
{
	return x.value<y.value || (x.value==y.value && x.r<y.r);
}
inline void fun(int k)
{
	if(k==0)
		return;
	printf("%d %d\n",t[k].l,t[k].r);
	fun(pre[k]);
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read()+a[i-1];
	for(register int i=1;i<=n;++i)
		for(register int j=i;j<=n;++j)
			t[++num].l=i,t[num].r=j,t[num].value=a[j]-a[i-1];
	sort(t+1,t+num+1,cmp);
	int last=1,ans=1,road=1;
	for(register int i=2;i<=num;++i)
		if(t[i].value!=t[i-1].value)
		{
			int number=1,bj=last;
			for(register int j=last+1;j<i;++j)
				if(t[j].l>t[bj].r)
					++number,pre[j]=bj,bj=j;
			if(number>ans)
				road=bj,ans=number;
			last=i;
		}
	int number=1,bj=last;
	for(register int j=last+1;j<=num;++j)
		if(t[j].l>t[bj].r)
			++number,pre[j]=bj,bj=j;
	if(number>ans)
		road=bj,ans=number;
	printf("%d\n",ans);
	fun(road);
	return 0;
}