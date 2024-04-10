#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100
#define V 200
using namespace std;
int n,a[N+5],s[N+5],f[N+5][N*V+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
	I void writeln() {pc('\n');}
}using namespace FastIO;
int P[N*V+5];I bool IsP(CI x) {for(RI i=2;i*i<=x;++i) if(!(x%i)) return 0;return 1;}
I void Print(CI x,CI y) {if(!x) return;if(y<=s[x-1]&&f[x-1][y]==f[x][y]) Print(x-1,y);else Print(x-1,y-a[x]),write(x);}
int main()
{
	RI Tt,i,j,t=0;for(i=2;i<=N*V;++i) P[i]=IsP(i);read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) for(read(a[i]),s[i]=s[i-1]+a[i],j=1;j<=s[i];++j) f[i][j]=-1e9;
		for(i=1;i<=n;++i) for(j=0;j<=s[i-1];++j) f[i][j]=max(f[i][j],f[i-1][j]),f[i][j+a[i]]=max(f[i][j+a[i]],f[i-1][j]+1);
		for(t=0,i=4;i<=s[n];++i) !P[i]&&f[n][i]>f[n][t]&&(t=i);writeln(f[n][t]),Print(n,t),writeln();
	}return clear(),0;
}