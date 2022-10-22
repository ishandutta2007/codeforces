#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 400000
using namespace std;
int n,k,a[N+5],c[N+5],ex[N+5],h[N+5],nxt[N+5];set<pair<int,int> > s;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int main()
{
	RI i;for(read(n,k),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) c[i]=1;
	for(i=1;i<=n;++i) h[i]=n+1;for(i=n;i;--i) nxt[i]=h[a[i]],h[a[i]]=i;
	RI t=0;for(i=1;i<=n;++i) ex[a[i]]?(s.erase(make_pair(i,a[i])),0):(s.size()==k&&(ex[(--s.end())->second]=0,s.erase(*--s.end()),0),++t),s.insert(make_pair(nxt[i],a[i])),ex[a[i]]=1;
	return printf("%d\n",t),0;
}