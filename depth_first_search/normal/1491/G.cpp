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
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,p[N+5],vis[N+5],c[N+5],qt,qx[N+5],qy[N+5];vector<int> g[N+5];
#define PB(x,y) (qx[++qt]=x,qy[qt]=y)
I void Solve(CI o)
{
	if(g[o].size()==2) {RI x=g[o][0],y=g[o][1],z=x^1&&y^1?1:(x^2&&y^2?2:3);PB(x,z),PB(y,z),PB(x,z);return;}
	RI x=g[o][0],y=g[o][1],z=g[o][2];PB(x,z);for(RI i=3,w=g[o].size();i^w;++i) PB(x,g[o][i]);PB(x,y),PB(y,z),PB(x,z);
}
I void Solve2(CI A,CI B)
{
	if(g[A].size()<g[B].size()) return Solve2(B,A);
	reverse(++g[B].begin(),g[B].end());RI i,wA=g[A].size(),wB=g[B].size();
	for(i=0;i^wB;++i) PB(g[A][i],g[B][i]);for(;i^wA;++i) PB(g[A][i],g[B][wB-1]);
	PB(g[A][0],g[B][wB-1]);for(i=1;i^wB;++i) PB(g[A][i],g[B][i-1]);
}
int main()
{
	RI i,x;for(read(n),i=1;i<=n;++i) read(p[i]);
	RI ct=0;for(i=1;i<=n;++i) if(!vis[i]&&p[i]^i)
		{g[++ct].push_back(i),vis[i]=1;for(x=p[i];x^i;x=p[x]) g[ct].push_back(x),vis[x]=1;}
	for(i=1;i<ct;i+=2) Solve2(i,i+1);if(ct&1) Solve(ct);
	for(writeln(qt),i=1;i<=qt;++i) write(qx[i]),writeln(qy[i]);return clear(),0;
}