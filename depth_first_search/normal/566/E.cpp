#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000
using namespace std;
int n,p[N+5],w[N+5][N+5];bitset<N+5> s,S[N+5],E[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);}
	Tp I void writeln(Con Ty& x,Con Ty& y) {write(x),pc(' '),write(y),pc('\n');}
}using namespace FastIO;
int main()
{
	#define Exit return clear(),0
	RI i,j,x,y;for(read(n),i=1;i<=n;++i) for(read(x);x;--x) read(y),S[i].set(y);if(n==2) {writeln(1,n);Exit;}
	for(i=1;i<=n;++i) {for(j=1;j<=n&&S[i].test(j);++j);if(j<=n) break;}if(i>n) {for(i=2;i<=n;++i) writeln(1,i);Exit;}
	RI t=0;for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) (s=S[i]&S[j]).count()==2&&(x=s._Find_first(),
		y=s._Find_next(x),!w[x][y]&&(writeln(x,y),E[x].set(y),E[y].set(x),p[x]=p[y]=w[x][y]=w[y][x]=1,++t));
	if(t==1) {for(i=1;i<=n&&S[i].count()==n;++i);for(j=1;j<=n;++j) !p[j]&&(writeln(S[i].test(j)?x:y,j),0);Exit;}
	for(i=1;i<=n;++i) p[i]&&(E[i].set(i),0);for(i=1;i<=n;++i) if(!p[i]) 
	{
		for(t=0,j=1;j<=n;++j) S[j].test(i)&&(!t||S[j].count()<S[t].count())&&(t=j);
		for(s.reset(),j=1;j<=n;++j) S[t].test(j)&&p[j]&&(s.set(j),0);for(j=1;j<=n;++j) if(E[j]==s) {writeln(i,j);break;}
	}return clear(),0;
}