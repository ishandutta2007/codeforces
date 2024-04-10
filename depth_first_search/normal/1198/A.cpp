#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 400000
#define INF 1e9
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m,t,a[N+5],s[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}F;
int main()
{
	RI i,p1,p2,ans=INF;for(F.read(n,m),i=1;i<=n;++i) F.read(a[i]);
	for(sort(a+1,a+n+1),i=1;i<=n;++i) s[i]=a[i];t=unique(s+1,s+n+1)-s-1;
	if(m=8*m/n,m>=30) return puts("0"),0;if(m=(1LL<<m),m>t) return puts("0"),0;
	for(p1=p2=i=1;i+m-1<=t;++i)
	{
		W(p1^n&&a[p1]<s[i]) ++p1;W(p2^n&&a[p2+1]<=s[i+m-1]) ++p2;
		Gmin(ans,(p1-1)+(n-p2));
	}return printf("%d",ans),0;
}