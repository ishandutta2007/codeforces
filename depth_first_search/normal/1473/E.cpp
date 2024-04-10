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
#define M 250000
#define LL long long
#define Pr pair<LL,int>
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,m,ee,lnk[N+5];struct edge {int to,nxt,v;}e[2*M+5];
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
	I void NA() {pc('-'),pc('1'),pc(' ');}
}using namespace FastIO;
LL dis[4*N+5];int vis[4*N+5];priority_queue<Pr,vector<Pr>,greater<Pr> > Q;I void Dij()
{
	#define T(y,d) (d<dis[y]&&(Q.push(make_pair(dis[y]=d,y)),0))
	RI i,x,o;Pr k;for(i=1;i<=4*n;++i) dis[i]=1e18;Q.push(make_pair(dis[1]=0LL,1));W(!Q.empty())
		if(k=Q.top(),Q.pop(),!vis[k.second]) for(x=(k.second-1)%n+1,o=(k.second-1)/n,vis[k.second]=1,i=lnk[x];i;i=e[i].nxt)
			T(e[i].to+o*n,k.first+e[i].v),!(o&1)&&T(e[i].to+(o|1)*n,k.first+2*e[i].v),!(o&2)&&T(e[i].to+(o|2)*n,k.first),!(o&3)&&T(e[i].to+3*n,k.first+e[i].v);
}
int main()
{
	RI i,x,y,z;for(read(n,m),i=1;i<=m;++i) read(x,y,z),add(x,y,z),add(y,x,z);
	for(Dij(),i=2;i<=n;++i) vis[i+3*n]?write(dis[i+3*n]):NA();return clear(),0;
}