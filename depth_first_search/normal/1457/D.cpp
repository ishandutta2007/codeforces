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
using namespace std;
int n,a[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
}F;
int main()
{
	RI i,j,k;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=n-2;++i) if(a[i]>(a[i+1]^a[i+2])) return puts("1"),0;
	RI p,q,ans=n;for(i=1;i<=n;++i) for(p=0,j=i;j<=n;++j)
		for(p^=a[j],q=0,k=j+1;k<=n;++k) if(p>(q^=a[k])) {ans=min(ans,k-i-1);}
	return ans^n?printf("%d\n",ans):puts("-1"),0;
}