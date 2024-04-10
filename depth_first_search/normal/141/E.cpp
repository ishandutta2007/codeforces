#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define M 100000
using namespace std;
int n,m,f[N+5],p[M+5];struct edge {int x,y,op;}s[M+5];
I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	I void readc(char& x) {W(isspace(x=tc()));}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int main()
{
	#define NA() return puts("-1"),0 
	RI i;char c;if(read(n,m),!(n&1)) NA();for(i=1;i<=m;++i) read(s[i].x,s[i].y),readc(c),s[i].op=c=='S';
	RI x,y,t=0;for(i=1;i<=m;++i) s[i].op&&(x=fa(s[i].x))^(y=fa(s[i].y))&&(f[x]=y,p[i]=1,++t);if(t<(n-1>>1)) NA();
	for(i=1;i<=m;++i) !s[i].op&&(x=fa(s[i].x))^(y=fa(s[i].y))&&(f[x]=y,p[i]=1,++t);if(t<n-1) NA();
	for(memset(f,0,sizeof(f)),t=0,i=1;i<=m;++i) !s[i].op&&p[i]&&(f[fa(s[i].x)]=s[i].y,++t);
	for(i=1;i<=m&&t<(n-1>>1);++i) !s[i].op&&!p[i]&&(x=fa(s[i].x))^(y=fa(s[i].y))&&(f[x]=y,p[i]=1,++t);if(t<(n-1>>1)) NA();
	for(i=1;i<=m;++i) s[i].op&&p[i]&&((x=fa(s[i].x))^(y=fa(s[i].y))?f[x]=y:p[i]=0);
	for(printf("%d\n",n-1),i=1;i<=m;++i) p[i]&&(write(i),0);return clear(),0;
}