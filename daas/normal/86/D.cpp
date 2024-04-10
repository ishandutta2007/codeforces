#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,q,base;
ll NOW,ans[200001],can[1000001],a[200001];
struct quest
{
	int l,r,id;
}Q[200001];
int cmp(quest x,quest y){return (x.l-1)/base==(y.l-1)/base?x.r<y.r:x.l<y.l;}
int main()
{
	n=read(),q=read();
	base=sqrt(n);
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=q;++i) Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+q+1,cmp);
	int l=1,r=1;
	can[a[1]]=1;
	NOW=a[1];
	for(int i=1;i<=q;++i)
	{
		while(r<Q[i].r)
		{
			++r;
			NOW-=a[r]*can[a[r]]*can[a[r]];
			++can[a[r]];
			NOW+=a[r]*can[a[r]]*can[a[r]];
		}
		while(Q[i].l<l)
		{
			--l;
			NOW-=a[l]*can[a[l]]*can[a[l]];
			++can[a[l]];
			NOW+=a[l]*can[a[l]]*can[a[l]];
		}
		while(l<Q[i].l)
		{
			NOW-=a[l]*can[a[l]]*can[a[l]];
			--can[a[l]];
			NOW+=a[l]*can[a[l]]*can[a[l]];
			++l;
		}
		while(Q[i].r<r)
		{
			NOW-=a[r]*can[a[r]]*can[a[r]];
			--can[a[r]];
			NOW+=a[r]*can[a[r]]*can[a[r]];
			--r;
		}
		ans[Q[i].id]=NOW;
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}