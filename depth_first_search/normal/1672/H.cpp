#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
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
	I void reads(char* s) {RI n=0;W(isspace(oc=tc()));W(s[++n]=oc,!isspace(oc=tc()));}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,a[N+5],f[N+5][2];char st[N+5];
int main()
{
	RI Qt,i;for(read(n,Qt),reads(st),i=2;i<=n;++i) f[i][0]=f[i-1][0],f[i][1]=f[i-1][1],st[i]==st[i-1]&&++f[i][st[i]&1];
	RI x,y;W(Qt--) read(x,y),writeln(max(f[y][0]-f[x][0],f[y][1]-f[x][1])+1);return clear(),0;
}