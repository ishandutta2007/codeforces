#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define INF (int)1e9
using namespace std;
int n,k,a[N+5],c[N+5],h[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
class MinCostMaxFlow
{
	private:
		#define PS (2*N+2)
		#define ES (5*N)
		#define s (2*n+1)
		#define t (2*n+2)
		#define E(x) ((((x)-1)^1)+1)
		int ee,lnk[PS+5];struct edge {int to,nxt,F,C;}e[2*ES+5];
		int lst[PS+5],IQ[PS+5],F[PS+5],C[PS+5];queue<int> q;
		I bool SPFA()
		{
			RI i,k;for(i=1;i<=t;++i) F[i]=C[i]=INF;q.push(s),C[s]=0;
			W(!q.empty()) for(i=lnk[k=q.front()],q.pop(),IQ[k]=0;i;i=e[i].nxt)
			{
				if(!e[i].F||C[k]+e[i].C>=C[e[i].to]) continue;
				C[e[i].to]=C[k]+e[lst[e[i].to]=i].C,F[e[i].to]=min(F[k],e[i].F),
				!IQ[e[i].to]&&(q.push(e[i].to),IQ[e[i].to]=1);
			}return F[t]^INF;
		}
	public:
		I void Add(CI x,CI y,CI f,CI c)
		{
			e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f,e[ee].C=c,
			e[++ee].nxt=lnk[y],e[lnk[y]=ee].to=x,e[ee].F=0,e[ee].C=-c;
		}
		I int MCMF()
		{
			RI x,g=0;W(SPFA()) {g+=C[t]*F[t],x=t;
				W(x^s) e[lst[x]].F-=F[t],e[E(lst[x])].F+=F[t],x=e[E(lst[x])].to;}
			return g;
		}
}D;
int main()
{
	RI i;for(read(n,k),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(c[i]);
	for(i=1;i<=n;++i) D.Add(s,i,1,c[a[i]]),D.Add(i,i+n,1,0),D.Add(i+n,t,1,0),
		i^n&&(D.Add(i,i+1,k-1,0),0),i^1&&h[a[i]]&&(D.Add(i-1,h[a[i]]+n,1,-c[a[i]]),0),h[a[i]]=i;
	return printf("%d\n",D.MCMF()),0;
}