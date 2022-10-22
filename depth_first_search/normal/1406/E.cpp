#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define A(x) (printf("A %d\n",x),fflush(stdout),scanf("%d",&res),res)
#define B(x) (printf("B %d\n",x),fflush(stdout),scanf("%d",&res),res)
#define C(x) (printf("C %d\n",x),fflush(stdout))
using namespace std;
int n,s,res,Pt,P[N+5],V[N+5];
I void Sieve()
{
	for(RI i=2,j;i<=n;++i) for(!P[i]&&(P[++Pt]=i),
		j=1;j<=Pt&&i*P[j]<=n;++j) if(P[i*P[j]]=1,!(i%P[j])) break;
}
I int Work(CI l,CI r) {for(RI i=l;i<=r;++i) if(A(P[i])) return P[i];}
int main()
{
	RI i,t=0;scanf("%d",&n),s=sqrt(n),Sieve();
	for(i=1;i<=Pt&&P[i]<=s;++i) B(P[i]),A(P[i])&&(V[++t]=P[i]);
	RI cur=i;if(t)
	{
		RI ans=1;for(i=1;i<=t;++i) ans*=V[i];
		for(i=1;i<=t;++i) W(ans*V[i]<=n&&A(ans*V[i])) ans*=V[i];
		for(i=cur;i<=Pt;++i) if(A(P[i])==2) return C(ans*P[i]),0;
		return C(ans),0;
	}
	RI k=Pt-i+2;for(s=sqrt(k);i<=Pt;++i)
		if(B(P[i]),--k,++t==s) {if(A(1)^k) return C(Work(i-s+1,i)),0;t=0;}
	return C(A(1)^1?Work(Pt-t+1,Pt):1),0;
}