#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
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
int n,type[300001],head[300001],tot,size[300001];
struct sb
{
	int to,nextn;
}a[300001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
inline int fun(int u,int fa)
{
	if(!head[u])
	{
		size[u]=1;
		return 1;
	}
	int ans=0,minn=0x7f7f7f7f;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		int P=fun(v,u);
		size[u]+=size[v];
		if(type[u])
		{
			ans+=size[v];
			minn=min(minn,size[v]-P);
		}
		else
			ans+=P-1;
	}
	if(type[u])
		ans-=minn;
	else
		++ans;
	return ans;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		type[i]=read();
	for(register int i=2;i<=n;++i)
		ADD(read(),i);
	int P=fun(1,0);
	printf("%d\n",P);
    return 0;
}