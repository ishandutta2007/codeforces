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
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
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
	I void YES() {pc('Y'),pc('E'),pc('S'),pc('\n');}I void NO() {pc('N'),pc('O'),pc('\n');}
}using namespace FastIO;
int n,fg,ct,qx[N+5],qy[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
int d[N+5],g[N+5];queue<int> q[N+5][2];void dfs(CI x,CI lst=0)
{
	RI c=0;d[x]=lst>0;for(RI i=lnk[x],y;i;i=e[i].nxt)
		(y=e[i].to)^lst&&(dfs(y,x),q[x][g[y]].push(y),d[x]^=1,g[y]?++c:--c);
	if(x^1) (c<-1||c>2)&&(fg=0),g[x]=c<=0;else c&&c^1&&(fg=0);
}
void Get(CI x)
{
	RI k=q[x][d[x]].front();q[x][d[x]].pop(),d[k]^d[x]&&(Get(k),0),d[qx[++ct]=x]^=1,d[qy[ct]=k]^=1;
}
void Del(CI x,CI lst=0)
{
	RI k;W(!q[x][d[x]].empty()) k=q[x][d[x]].front(),
		q[x][d[x]].pop(),d[k]^d[x]&&(Get(k),0),d[qx[++ct]=x]^=1,d[qy[ct]=k]^=1;
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(Del(e[i].to,x),0);
}
int main()
{
	RI Tt,i,x,y,H=1,T=0;read(Tt);W(Tt--)
	{
		for(read(n),ee=0,i=1;i<=n;++i) {lnk[i]=0;W(!q[i][0].empty()) q[i][0].pop();W(!q[i][1].empty()) q[i][1].pop();}
		for(i=1;i^n;++i) read(x,y),add(x,y),add(y,x);if(fg=1,dfs(1),!fg) {NO();continue;}
		for(ct=0,Del(1),YES(),i=1;i<=ct;++i) write(qx[i]),writeln(qy[i]);
	}return clear(),0;
}