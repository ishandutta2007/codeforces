#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//_   //
int op[525],tt,gg,hh,g,ins[505],f[505],fa[505],n,m,a[505],v[505],fl,u,v_,tot,c[100005][2];

void dfsA(int p)
{
	if(fl)return;
	v[p]=1; ins[p]=1;
	for(int o=a[p]; o; o=c[o][1])
	{
		if(o==g)continue;
		if(v[c[o][0]])
		{
			if(!ins[c[o][0]])continue;
			fl=1;
			break;//return
		}
		dfsA(c[o][0]);
	}
	ins [ p]=0;
}

void dfs(int p)
{
	if(tt)return;
//	if(fl)return;
	v[p]=1; ins[p]=1;
	for(int o=a[p]; o; o=c[o][1])
	{
		if(v[c[o][0]])
		{
			if(!ins[c[o][0]])continue;
			if(tt)continue;
			gg=hh=c[o][0];
//			op[++tt]=f[c[o][0]];
			hh=p; op[++tt]=o;  //tt=1
//			hh=fa[c[o][0]];
			while(hh!=gg)
			{
				op[++tt]=f[hh];
			    hh=fa[hh];
			}
			continue;
		}
		fa[c[o][0]]=p;
		f[c[o][0]]=o;
		dfs(c[o][0]);
	}
	ins [ p]=0;
}

int main()
{
	n=read(); m=read();
	for(int i=1; i<=m; ++i)
	{
		u=read(); v_=read();
		c[++tot][0]=v_; c[tot][1]=a[u]; a[u]=tot;
	}
//	fl=0
	for(int i=1; i<=n; ++i)if(!v[i])dfs(i);
	if(!tt)
	{
		puts("YES");
		return 0;//exit(0)
	}
	for(int i=1; i<=tt; ++i)
	{
		g=op[i];
		fl=0;
		memset(v,0,sizeof(v)); //
		for(int i=1; i<=n; ++i)if(!v[i])dfsA(i);
		if(!fl){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}