#include<bits/stdc++.h>
#define N 100000
#define P 100
#define INF 1e18
#define LL long long
using namespace std;
LL n,m,p,a[N+5],dis[N+5],sum[N+5];
class Class_FIO
{
	private:
		#define Fsize 100000
		#define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
		#define pc(ch) (void)(putchar(ch))
		LL Top;char ch,*A,*B,Fin[Fsize],Stack[Fsize];
	public:
		inline void read(LL &x) {x=0;while(!isdigit(ch=tc()));while(x=(x<<3)+(x<<1)+(ch&15),isdigit(ch=tc()));}
		inline void write(LL x) {if(!x) return pc('0');while(x) Stack[++Top]=x%10+48,x/=10;while(Top) pc(Stack[Top--]);}
}F;
class Class_SlopeDP
{
	private:
		LL q[N+5],f[N+5][P+5];
	public:
		inline void Solve()
		{
			register LL i,j,H,T;
			for(i=1;i<=m;++i) f[i][0]=INF;
			for(j=1;j<=p;++j)
			{
				for(q[H=T=1]=0,i=1;i<=m;++i)
				{
					while(H<T&&f[q[H+1]][j-1]+sum[q[H+1]]-f[q[H]][j-1]-sum[q[H]]<=(q[H+1]-q[H])*a[i]) ++H;
					f[i][j]=f[q[H]][j-1]+a[i]*(i-q[H])-sum[i]+sum[q[H]];
					while(H<T&&(f[i][j-1]+sum[i]-f[q[T]][j-1]-sum[q[T]])*(q[T]-q[T-1])<=(f[q[T]][j-1]+sum[q[T]]-f[q[T-1]][j-1]-sum[q[T-1]])*(i-q[T])) --T;
					q[++T]=i;
				}
			}
			F.write(f[m][p]);
		}
}SlopeDP;
int main()
{
	register LL i,x,y;
	for(F.read(n),F.read(m),F.read(p),i=2;i<=n;++i) F.read(x),dis[i]=dis[i-1]+x;
	for(i=1;i<=m;++i) F.read(x),F.read(y),a[i]=y-dis[x];
	for(sort(a+1,a+m+1),i=1;i<=m;++i) sum[i]=sum[i-1]+a[i];
	return SlopeDP.Solve(),0;
}