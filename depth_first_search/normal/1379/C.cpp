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
#define LL long long
using namespace std;
int n,m;
struct Data
{
	int x,y;I Data(CI a=0,CI b=0):x(a),y(b){}
	I bool operator < (Con Data& o) Con {return x>o.x;}
}s[N+5],g[N+5];
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
	RI Tt,i,j,k;LL ans,cur;F.read(Tt);W(Tt--)
	{
		for(F.read(n),F.read(m),i=1;i<=m;++i) F.read(s[i].x),F.read(s[i].y);
		for(sort(s+1,s+m+1),i=1;i<=m;++i) g[i]=Data(s[i].y,i);sort(g+1,g+m+1);
		for(ans=0,i=1;i<=min(n,m);++i) ans+=s[i].x;
		for(cur=0,i=1,j=0;i<=m;++i)
		{
			W(j^n&&j^m&&s[j+1].x>g[i].x) cur+=s[++j].x;if((k=j+(g[i].y>j))>n) continue;
			ans=max(ans,cur+(g[i].y>j)*s[g[i].y].x+1LL*(n-k)*g[i].x);
		}printf("%lld\n",ans);
	}return 0;
}