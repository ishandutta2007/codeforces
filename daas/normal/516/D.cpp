#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
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
int n,q,head[100001],tot,dis[100001],Fa[100001],F[100001],id[100001],root,far;
int father[100001],size[100001],ans[100001],cnt[100001];
struct sb
{
	int to,nextn,l;
}a[200001];
void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].l=l;
	head[from]=tot;
}
void find(int u,int fa)
{
	if(dis[u]>dis[far])
		far=u;
	Fa[u]=fa;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		dis[v]=dis[u]+a[i].l;
		find(v,u);
	}
}
int cmp(int x,int y)
{
	return F[x]>F[y] || (F[x]==F[y] && abs(x-root)>abs(y-root));
}
int find(int k)
{
	if(father[k]!=k)
		father[k]=find(father[k]);
	return father[k];
}
signed main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),l=read();
		ADD(u,v,l);
		ADD(v,u,l);
	}
	find(1,0);
	dis[far]=0;
	find(far,0);
	for(int i=1;i<=n;++i)
		F[i]=max(F[i],dis[i]);
	dis[far]=0;
	find(far,0);
	for(int i=1;i<=n;++i)
		F[i]=max(F[i],dis[i]),id[i]=i;
	root=1;
	for(int i=1;i<=n;++i)
		if(F[i]<F[root])
			root=i;
	find(root,0);
	sort(id+1,id+n+1,cmp);
	q=read();
	while(q--)
	{
		int lim=read(),ANS=1,l=1,out=1;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
			father[i]=i,size[i]=1,ans[i]=1;
		cnt[1]=n;
		for(int i=1;i<=n;++i)
		{
			for(int j=head[id[i]];j!=0;j=a[j].nextn)
			{
				int v=a[j].to;
				if(v==Fa[id[i]])
					continue;
				int au=find(id[i]),av=find(v);
				if(size[au]>size[av])
					swap(au,av);
				size[av]+=size[au];
				father[au]=av;
				cnt[ans[av]]--;
				cnt[ans[au]]--;
				ans[av]+=ans[au];
				if(ans[av]>ANS)
					ANS=ans[av];
				cnt[ans[av]]++;
			}
			while(F[id[l]]-F[id[i]]>lim)
			{
				int au=find(id[l]);
				cnt[ans[au]]--;
				if(ans[au]==ANS && !cnt[ans[au]])
					--ANS;
				ans[au]--;
				cnt[ans[au]]++;
				++l;
			}
			out=max(out,ANS);
		}
		printf("%lld\n",out);
	}
	return 0;
}//