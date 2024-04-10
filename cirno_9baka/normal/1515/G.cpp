#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,u,v,w,i,insta[N],dfn[N],low[N],sta[N],top,c[N],k,tot,q;
long long dep[N],t[N],s,tr,e[N];
struct str{
	int v,w;
};
vector<str> g[N];
void Tarjan(int i)
{
	int j;
	low[i]=dfn[i]=++k;
	sta[++top]=i;
	insta[i]=1;
	for(auto j:g[i])
		if(!dfn[j.v])
		{
			dep[j.v]=dep[i]+j.w;
			Tarjan(j.v);
			low[i]=min(low[i],low[j.v]);
		}
		else
			if(insta[j.v])
			{
				low[i]=min(low[i],dfn[j.v]);
				t[i]=__gcd(t[i],j.w+dep[i]-dep[j.v]);
			}
	if(dfn[i]==low[i])
	{
		++tot;
		while(1)
		{
			c[sta[top]]=tot;
			insta[sta[top]]=0;
			if(sta[top]==i)
				break;
			--top;
		}
		--top;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
	}
	for(i=1;i<=n;++i)
		if(!dfn[i])
			Tarjan(i);
	for(i=1;i<=n;++i)
		e[c[i]]=__gcd(e[c[i]],t[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %lld %lld",&v,&s,&tr);
		if(__gcd(s,tr)%__gcd(e[c[v]],tr)==0)
			puts("YES");
		else
			puts("NO");
	}
}