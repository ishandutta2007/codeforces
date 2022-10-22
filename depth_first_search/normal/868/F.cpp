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
#define K 20
#define LL long long
using namespace std;
int n,k,a[N+5];LL f[K+1][N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int L=1,R=0,c[N+5];LL t=0;I LL Calc(CI l,CI r)
{
	W(R<r) t+=c[a[++R]]++;W(L>l) t+=c[a[--L]]++;W(R>r) t-=--c[a[R--]];W(L<l) t-=--c[a[L++]];return t;
}
I void DP(CI id,CI l,CI r,CI L,CI R)
{
	if(l>r) return;RI i,mid=l+r>>1,p=L;LL v=f[id-1][p]+Calc(p+1,mid);
	for(i=L+1;i<mid&&i<=R;++i) f[id-1][i]+Calc(i+1,mid)<v&&(v=f[id-1][p=i]+Calc(i+1,mid));f[id][mid]=v;
	DP(id,l,mid-1,L,p),DP(id,mid+1,r,p,R);
}
int main()
{
	RI i,j;for(read(n,k),i=1;i<=n;++i) read(a[i]);
	for(i=0;i<=k;++i) for(j=0;j<=n;++j) f[i][j]=1e18;f[0][0]=0;
	for(i=1;i<=k;++i) DP(i,i,n,0,n-1);return printf("%lld\n",f[k][n]),0;
}