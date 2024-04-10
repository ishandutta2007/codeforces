#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
const LL MX=100100,inf=0x3f3f3f3f;
LL n,M,Mn;
LL ans;
struct Edge{LL to,nxt,w;}e[MX<<1];
LL hed[MX],ec,P10[MX],Pn10[MX];
LL vis[MX],vis1[MX],O,mns,cc,mxs[MX],cnt[MX];
map<LL,LL>F[MX];

inline void rd(LL &x)
{
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
}
inline void ade(LL f,LL t,LL w)
{e[++ec].to=t;e[ec].nxt=hed[f];hed[f]=ec;e[ec].w=w;}
void exgcd(LL &x,LL &y,LL a,LL b)
{
	if(b==0){x=1,y=0;return;}
	exgcd(y,x,b,a%b);
	y-=(a/b)*x;
}
inline void dfso2(LL k)
{
	vis1[k]=1;
	if(max(cc-cnt[k],mxs[k])<mns)
	{
		O=k;mns=max(cc-cnt[k],mxs[k]);
	}
	for(LL i=hed[k];i;i=e[i].nxt)
	{
		if(vis[e[i].to]||vis1[e[i].to])continue;
		dfso2(e[i].to);
	}
	vis1[k]=0;
}
inline void dfso(LL k)
{
	cc++;mxs[k]=0;cnt[k]=1;vis1[k]=1;
	for(LL i=hed[k];i;i=e[i].nxt)
	{
		if(vis[e[i].to]||vis1[e[i].to])continue;
		dfso(e[i].to);
		cnt[k]+=cnt[e[i].to];mxs[k]=max(mxs[k],cnt[e[i].to]);
	}
	vis1[k]=0;
}
inline void geto(LL k)
{
	cc=0;
	dfso(k);
	mns=inf;
	dfso2(k);
}
inline void dfs(LL k,LL v,LL f,LL l)
{
	F[f][v]++;vis1[k]=1;
	for(LL i=hed[k];i;i=e[i].nxt)
	{
		if(vis[e[i].to]||vis1[e[i].to])continue;
		dfs(e[i].to,(v+(long long)e[i].w*P10[l])%M,f,l+1);
	}
	vis1[k]=0;
}
long long tmp;
inline void dfs2(LL k,LL v,LL f,LL l)
{
	vis1[k]=1;
	LL m=((M-v)%M*Pn10[l])%M;
	tmp+=F[O][m]-F[f][m];
	for(LL i=hed[k];i;i=e[i].nxt)
	{
		if(vis[e[i].to]||vis1[e[i].to])continue;
		dfs2(e[i].to,(v*10+e[i].w)%M,f,l+1);
	}
	vis1[k]=0;
}
void wk(LL k)
{
	tmp=0;
	geto(k);
	F[O].clear();
	dfs(O,0,O,0);
	tmp=F[O][0]-1;
	vis[O]=1;
	for(LL i=hed[O];i;i=e[i].nxt)
	{
		if(vis[e[i].to])continue;
		F[e[i].to].clear();
		dfs(e[i].to,e[i].w%M,e[i].to,1);
		dfs2(e[i].to,e[i].w%M,e[i].to,1);
	}
	ans+=tmp;
	for(LL i=hed[O];i;i=e[i].nxt)
	if(!vis[e[i].to])wk(e[i].to);
}
int main()
{
	//freopen("tst.in","r",stdin);
	//freopen("tst.out","w",stdout);
	rd(n);rd(M);
	LL y;
	if(10>M)exgcd(Mn,y,10,M);else exgcd(y,Mn,M,10);
	if(Mn<0)Mn=(M-(-Mn)%M)%M;
	P10[0]=1;Pn10[0]=1;
	for(LL i=1;i<=n;i++)
	{
		P10[i]=(P10[i-1]*10)%M;
		Pn10[i]=(Pn10[i-1]*Mn)%M;
	}
	for(LL i=1;i<n;i++)
	{
		LL a,b,x;
		rd(a);rd(b);rd(x);
		a++;b++;
		ade(a,b,x);
		ade(b,a,x);
	}
	wk(1);
	printf("%I64d\n",ans);
	return 0;
}