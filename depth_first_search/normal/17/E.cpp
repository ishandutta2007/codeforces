#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2000000
#define X 51123987
using namespace std;
int n,m,p[2*N+5],f1[N+5],g1[N+5],f2[N+5],g2[N+5];char s[N+5],ns[2*N+5];
int main()
{
	RI i;for(scanf("%d%s",&n,s+1),ns[1]='!',ns[m=2]='%',i=1;i<=n;++i) ns[++m]=s[i],ns[++m]='%';ns[++m]='?';
	RI id,Mx=0;for(i=1;i<=m;i+p[i]-1>Mx&&(Mx=i+p[id=i]-1),++i) for(p[i]=i<=Mx?min(p[id]+id-i,p[2*id-i]):0;ns[i-p[i]]==ns[i+p[i]];++p[i]);
	RI x,y,z;for(i=3;i<m;i+=2) x=(i-p[i]>>1)+1,y=i>>1,z=(i+p[i]>>1)-1,++g1[x],----g1[y+1],++g1[z+2],++g2[x],--g2[y],--g2[y+1],++g2[z+1];
	for(i=4;i<m-1;i+=2) x=(i-p[i]>>1)+1,y=i>>1,z=(i+p[i]>>1)-1,++g1[x],--g1[y],--g1[y+1],++g1[z+2],++g2[x],----g2[y],++g2[z+1];
	for(i=1;i<=n;++i) g1[i]+=g1[i-1],g2[i]+=g2[i-1],f1[i]=(f1[i-1]+g1[i]+X)%X,f2[i]=(f2[i-1]+g2[i]+X)%X;
	RI t=0;for(i=1;i<=n;++i) t=(t+1LL*f1[i]*(f1[i]-1)/2)%X,t=(t-1LL*f2[i]*(f2[i]-1)/2%X+X)%X;return printf("%d\n",t),0;
}