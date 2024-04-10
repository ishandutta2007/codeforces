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
using namespace std;
int L[N+5],R[N+5];
I void Work(RI x,RI y,RI nw=1)
{
	RI i;for(y-=x-1,i=0;y<L[i]+L[x-1-i]||y>R[i]+R[x-1-i];++i);
	RI a,b;if(L[i]+R[x-1-i]>=y) a=L[i],b=y-a;else b=R[x-1-i],a=y-b;
	i&&(printf("%d ",nw),Work(i,a,nw+1),0),x-1-i&&(printf("%d ",nw),Work(x-1-i,b,nw+1+i),0);
}
int main()
{
	RI Qt,i,j;for(i=2;i<=N;L[i]+=i-1,R[i]+=i-1,++i) for(L[i]=1e9,j=0;j^i;++j) L[i]=min(L[i],L[j]+L[i-1-j]),R[i]=max(R[i],R[j]+R[i-1-j]);
	RI x,y;scanf("%d",&Qt);W(Qt--) scanf("%d%d",&x,&y),L[x]<=y&&y<=R[x]?(puts("YES"),Work(x,y,1),putchar('\n')):puts("NO");return 0;
}