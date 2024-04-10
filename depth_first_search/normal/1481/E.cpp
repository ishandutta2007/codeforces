#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
using namespace std;
int n,a[N+5],f[N+5],Mn[N+5],Mx[N+5],tot[N+5],suf[N+5],cnt[N+5];
struct Data
{
	int l,r,v;I Data(CI a=0,CI b=0,CI c=0):l(a),r(b),v(c){}
	I bool operator < (Con Data& o) Con {return r<o.r;}
}s[N+5];
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
	RI i;for(F.read(n),i=1;i<=n;++i) F.read(a[i]),!Mn[a[i]]&&(Mn[a[i]]=i),Mx[a[i]]=i;
	for(i=n;i;--i) suf[i]=max(++cnt[a[i]],suf[i+1]);
	RI t=0;for(i=1;i<=n;++i) Mx[i]&&(s[++t]=Data(Mn[i],Mx[i],cnt[i]),0);sort(s+1,s+t+1);
	RI p=1;for(i=1;i<=n;f[i]=max(f[i],f[i-1]),++i) W(s[p].r==i) f[i]=max(f[i],f[s[p].l-1]+s[p].v),++p;
	RI ans=0;for(i=1;i<=n;++i) ans=max(ans,f[i]+suf[i+1]);return printf("%d\n",n-ans),0;
}