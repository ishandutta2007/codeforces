#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
#define LN 20
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,s[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];vector<pair<int,int> > p[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
}using namespace FastIO;
int D[N+5],f[N+5][LN+1];I void Init(CI x=1)
{
	RI i;for(i=1;i<=LN;++i) f[x][i]=f[f[x][i-1]][i-1];
	for(i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&(D[e[i].to]=D[f[e[i].to][0]=x]+1,Init(e[i].to),0);
}
I int LCA(RI x,RI y)
{
	RI i;for(D[x]<D[y]&&(swap(x,y),0),i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=f[x][i]);if(x==y) return x;
	for(i=LN;~i;--i) f[x][i]^f[y][i]&&(x=f[x][i],y=f[y][i]);return f[x][0];
}
I int Jump(RI x,CI z)
{
	if(x==z) return 0;for(RI i=0;D[x]^(D[z]+1);++i) (D[x]^(D[z]+1))>>i&1&&(x=f[x][i]);return x;
}
long long ans;map<pair<int,int>,int> G;I void dfs(CI x=1)
{
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&(dfs(e[i].to),s[x]+=s[e[i].to]);
	RI t=s[x]-p[x].size();vector<pair<int,int> >::iterator it;
	for(it=p[x].begin();it!=p[x].end();++it) ++G[make_pair(it->first,it->second)];
	for(it=p[x].begin();it!=p[x].end();++it) s[x]-=2,--s[it->first],--s[it->second],--G[make_pair(it->first,it->second)],--t,
		ans+=t-(it->first?s[it->first]:0)-(it->second?s[it->second]:0)+(it->first&&it->second?G[make_pair(it->first,it->second)]:0);
}
int main()
{
	RI i,x,y,z;for(read(n),i=1;i^n;++i) read(x),read(y),add(x,y),add(y,x);
	for(Init(),read(m),i=1;i<=m;++i) read(x),read(y),++s[x],++s[y],
		z=LCA(x,y),(x=Jump(x,z))>(y=Jump(y,z))&&(swap(x,y),0),p[z].push_back(make_pair(x,y));
	return dfs(),printf("%lld\n",ans),0;
}