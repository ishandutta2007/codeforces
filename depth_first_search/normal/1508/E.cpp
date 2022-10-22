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
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
#define NA() (puts("NO"),exit(0))
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
int n,a[N+5],p[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
int f[N+5],D[N+5];void dfs(CI x,CI lst=0)
{
	for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^lst&&(D[y]=D[f[y]=x]+1,dfs(y,x),0);
}
int ct,rk[N+5],vis[N+5];void T(RI x)
{
	if(vis[x]) return;vis[x]=1,x^1&&(T(f[x]),0),rk[x]=++ct;
}
bool cmp(CI x,CI y) {return rk[x]<rk[y];}
int cI,cO,dI[N+5],qI[N+5],qO[N+5];vector<int> q[N+5];void Get(CI x)
{
	qI[dI[x]=++cI]=x;for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^f[x]&&(q[x].push_back(e[i].to),0);
	sort(q[x].begin(),q[x].end(),cmp);for(vector<int>::iterator it=q[x].begin();it!=q[x].end();++it) Get(*it);qO[++cO]=x;
}
void Move(CI x,CI t)
{
	if(x==t) return;for(vector<int>::iterator it=q[x].begin();it!=q[x].end();++it) if(a[*it]>a[x]) return Move(*it,t);NA();
}
int main()
{
	RI i,x,y;for(read(n),i=1;i<=n;++i) read(a[i]);for(i=1;i^n;++i) read(x,y),add(x,y),add(y,x);dfs(1);
	RI k=-1;long long ans=0;if(a[1]==1) for(i=1;i<=n;++i) rk[i]=a[i];else
	{
		for(i=1;i<=n;++i) a[i]<a[1]&&(ans+=D[i],a[i]==a[1]-1&&(k=i));
		x=k;W(x^1) swap(a[f[x]],a[x]),x=f[x];for(i=1;i<=n;++i) p[a[i]]=i;for(i=1;i<=n;++i) T(p[i]);
	}
	Get(1),~k&&(Move(1,k),0);for(i=1;i^a[1];++i) if(qO[i]^p[i]) NA();
	RI t=a[1];for(i=1;i<=n;++i) if(a[qI[i]]>=a[1]) {if(a[qI[i]]^t) NA();++t;}
	for(printf("YES\n%lld\n",ans),i=1;i<=n;++i) write(dI[i]);return clear(),0;
}