#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 100050
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int cnt[250005],ans[N],x,p,t1,t2,op,b[N],t,l,r,wqy[N],bel[N],n,q,a[N],bl;

//map<int,int>cnt;

map<int,int>s;
int tot;

//empty
//return s[0]

inline int dy(int x)
{
	//s[x]
	if(s.count(x))return s[x];
	return s[x]=++tot;
}

struct nod
{
	int u, v, p;
}g[N];

struct node
{
	int l, r, t, id;
	bool operator <(const node&a)const
	{
		if(bel[l]!=bel[a.l])return l<a.l;
		if(bel[r]!=bel[a.r])return r<a.r;
		if((bel[l]&1)^(bel[r]&1))return t>a.t;
		return t<a.t;
	}
}h[N];

inline void ch(int p, int x)
{
	if(p>=l && p<=r){
		--wqy[cnt[a[p]]];
		--cnt[a[p]];
		++wqy[cnt[a[p]]];
		    
		--wqy[cnt[x]];
		++cnt[x];
		++wqy[cnt[x]];
	}
	a[p]=x;
}

inline void add(int p)
{
	--wqy[cnt[p]];
	++cnt[p];
	++wqy[cnt[p]];
}

inline void dele(int p)
{
	--wqy[cnt[p]];
	--cnt[p];
	++wqy[cnt[p]];
}

inline int get_ans(int nl, int nr, int nt)
{
	while(t<nt){++t; ch(g[t].p,g[t].v); }
	while(t>nt){ ch(g[t].p, g[t].u);--t; }
	while(r<nr){add(a[++r]);}
	while(l>nl){add(a[--l]);}
	while(r>nr){dele(a[r--]);}
	while(l<nl){dele(a[l++]);}
	
	for(int i=1; i<=999; ++i)
	{
		if(!wqy[i])return i; 
	}
}

int main()
{
	int n=read(),q=read();
	for(int i=1; i<=n; ++i)b[i]=a[i]=dy(read());
	for(int i=1; i<=q; ++i){
		op=read();
		if(op==1)
		{
			h[++t2]=(node){read(),read(),t1,t2};
		}
		else
		{
			++t1;
			p=read(); x=dy(read());
			g[t1].p=p;
			g[t1].u=b[p];
			g[t1].v=b[p]=x;
		}
	}
	
	bl=max(1,(int)pow(n,2.0/3));
	for(int i=1; i<=n; ++i)bel[i]=(i-1)/bl;
	
	sort(h+1,h+t2+1);
	
	l=1; r=0; t=0;
	wqy[0]=110000;
	
	for(int i=1; i<=t2; ++i)
	{
		ans[h[i].id]=get_ans(h[i].l, h[i].r, h[i].t);
	}
	for(int i=1; i<=t2; ++i)printf("%d\n",ans[i]);
}