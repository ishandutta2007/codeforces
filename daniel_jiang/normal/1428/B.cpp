// wish to get better qwq
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e5+10;
struct Edge{ll to,nxt;}e[N<<1];
ll t,n,ans,emm,tp,cnt,sta[N],low[N], dfn[N],head[N];
bool vis[N];
inline void add(int u,int v){e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;}
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
inline void tarjan(int now) {
	sta[++tp]=now;vis[now]=true;low[now]=dfn[now]=++emm;
	for(ll i=head[now];i;i=e[i].nxt) {
		ll to=e[i].to;
		if(!dfn[to]){
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if(vis[to]){
			low[now]=min(low[now],dfn[to]);
		}
	}
	if(low[now]==dfn[now]){
		int to; int size=0;
		do{
			to=sta[tp--];
			vis[to]=false;
			++size;
		}while(to^now);
		if(size-1) ans+=size; 
	}
	return;
}
struct CartesianTree{
	struct node{
		int id,v,fa,ls,rs;
	}tr[N];
	inline void init(){tr[0].id=tr[0].v=tr[0].ls=tr[0].rs=tr[0].fa=0;}
	inline void insert(int x,int y,int z){
		tr[x].id=x;tr[x].v=y;tr[x].fa=z;tr[x].ls=tr[x].rs=0;
		int k=x-1;
		while(tr[k].v>tr[x].v) k=tr[k].fa;
		tr[x].ls=tr[k].rs;tr[k].rs=x;
		tr[x].fa=k;tr[tr[x].rs].fa=x;
	}
}CT;
int main() {
	rd(t);
	while(t--) {
		ans=0;rd(n);
		for(ll i=1;i<=n;++i) head[i]=low[i]=dfn[i]=0;
		tp=ans=emm=cnt=0;
		for(ll i=1;i<=n;++i){
			char c;cin>>c;if(c=='-')add(i,i%n+1),add(i%n+1,i);
			if(c=='<') add(i%n+1,i);if(c=='>') add(i,i%n+1);
		}
		for(register int i=1;i<=n;++i){if(!dfn[i])tarjan(i);}
		wr(ans);puts("");
	}
	return 0;
}