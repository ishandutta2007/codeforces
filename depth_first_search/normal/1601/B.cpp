#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
using namespace std;
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
}using namespace FastIO;
int n,a[N+5],b[N+5],q[N+5],f[N+5],h[N+5],lst[N+5];
void Print(CI x) {if(x==n) return;Print(lst[x]),write(h[x]);}
int main()
{
	RI i;for(read(n),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(b[i]);
	RI H,T;for(i=0;i^n;++i) f[i]=-1;f[q[H=T=1]=n]=0;
	RI k,o,p=n;W(H<=T&&!~f[0]) {k=q[H++];W(p>k-a[k]) --p,!~f[o=p+b[p]]&&(f[q[++T]=o]=f[k]+1,h[o]=p,lst[o]=k);}
	return printf("%d\n",f[0]),~f[0]&&(Print(0),clear(),0);
}