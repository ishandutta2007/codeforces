#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 5000
#define V 100000 
#define INF (int)1e9
using namespace std;
int n,ct,p[V+5],q[7];
namespace D
{
	#define PS 4*N+2
	#define ES 10*N
	#define s (2*n+1)
	#define t (2*n+2)
	#define add(x,y,f,c) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f,e[ee].C=c)
	int ee=1,lnk[PS+5];struct edge {int to,nxt,F,C;}e[2*ES+5];
	I void Add(CI x,CI y,CI f,CI c) {add(x,y,f,c),add(y,x,0,-c);}
	int p[PS+5],IQ[PS+5],C[PS+5];queue<int> q;I bool SPFA()
	{
		RI i;for(i=1;i<=ct;++i) C[i]=-INF;C[s]=0,q.push(s),IQ[s]=1;
		RI k;W(!q.empty()) for(IQ[k=q.front()]=0,q.pop(),i=lnk[k];i;i=e[i].nxt) e[i].F&&
			C[k]+e[i].C>C[e[i].to]&&(C[e[i].to]=C[k]+e[p[e[i].to]=i].C,!IQ[e[i].to]&&(q.push(e[i].to),IQ[e[i].to]=1));
		return C[t]!=-INF;
	}
	I void Flow() {RI x,g=0;for(RI i=0;i<=1&&SPFA();++i) {g+=C[x=t];W(x^s) --e[p[x]].F,++e[p[x]^1].F,x=e[p[x]^1].to;}printf("%d\n",g);}
}
int main()
{
	#define A(k,i) (++ct,k&&(D::Add(ct,k,INF,0),0),D::Add(ct,i,1,0),k=ct)
	RI i,x;for(scanf("%d",&n),ct=t,i=1;i<=n;++i) scanf("%d",&x),D::Add(i,n+i,1,1),
		p[x-1]&&(D::Add(n+i,p[x-1],1,0),0),p[x+1]&&(D::Add(n+i,p[x+1],1,0),0),q[x%7]&&(D::Add(n+i,q[x%7],1,0),0),A(p[x],i),A(q[x%7],i);
	for(i=1;i<=n;++i) D::Add(s,i,1,0),D::Add(n+i,t,1,0);return D::Flow(),0;
}