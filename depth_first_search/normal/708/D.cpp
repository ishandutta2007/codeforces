#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
#define INF (int)1e9
using namespace std;
int n,m,d[N+5];
class MinCostMaxFlow
{
	private:
		#define PS (N+2)
		#define ES (4*N)
		#define s (n+1)
		#define t (n+2)
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
	RI i,u,v,c,f,g=0;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d%d%d",&u,&v,&c,&f),d[u]+=f,d[v]-=f,
		f<=c?(D.Add(u,v,c-f,1),D.Add(u,v,INF,2),D.Add(v,u,f,1)):(D.Add(u,v,INF,2),g+=f-c,D.Add(v,u,f-c,0),D.Add(v,u,c,1));
	for(i=1;i<=n;++i) d[i]>0&&(D.Add(i,t,d[i],0),0),d[i]<0&&(D.Add(s,i,-d[i],0),0);
	return D.Add(n,1,INF,0),printf("%d\n",g+D.MCMF()),0;
}