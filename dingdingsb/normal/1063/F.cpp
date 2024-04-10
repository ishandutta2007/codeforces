#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e6+10,M=20;
namespace SAM{
	int sz=1,lst=1,fa[N],len[N],ch[N][26];
	int add(int c){
		int cur=++sz,p=lst;
		len[cur]=len[lst]+1;
		for(;p&&!ch[p][c];p=fa[p])
			ch[p][c]=cur;
		if(!p)fa[cur]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[cur]=q;
			else{
				int nw=++sz;
				len[nw]=len[p]+1;
				fa[nw]=fa[q];
				memcpy(ch[nw],ch[q],sizeof ch[nw]);
				for(;ch[p][c]==q;p=fa[p])
					ch[p][c]=nw;
				fa[q]=fa[cur]=nw;
			}
		}
		return lst=cur;
	}
}
using SAM::len;
struct SGT{
	int mx[N<<2];
	void mdf(int x,int l,int r,int p,int v){
		if(l==r)return mx[x]=v,void();
		if(p<=mid)mdf(lc,l,mid,p,v);
		else mdf(rc,mid+1,r,p,v);
		mx[x]=max(mx[lc],mx[rc]);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mx[x];
		if(r<ql||qr<l)return 0;
		return max(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
int n;char s[N];int pos[N];
vector<int>e[N];int fa[N][M];
int dfn[N],sz[N],cnt;
int dp[N];
void dfs(int u){
	sz[u]=1;dfn[u]=++cnt;
	for(int i=1;i<M;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		fa[v][0]=u;
		dfs(v);
		sz[u]+=sz[v];
	}
}
int jump(int x,int k){
	for(int i=M-1;~i;i--)
		if(len[fa[x][i]]>=k)
			x=fa[x][i];
	return x;
}
bool chk(int x){
	int pos1=jump(pos[x],dp[x]-1);
	int pos2=jump(pos[x-1],dp[x]-1);
	if(pos1&&T.qry(1,1,cnt,dfn[pos1],dfn[pos1]+sz[pos1]-1)+1>=dp[x])return 1;
	if(pos2&&T.qry(1,1,cnt,dfn[pos2],dfn[pos2]+sz[pos2]-1)+1>=dp[x])return 1;
	return 0;
}
signed main(){
	SAM::len[0]=-1;
	read(n);
	scanf("%s",s+1);
	reverse(s+1,s+1+n);
	for(int i=1;i<=n;i++)pos[i]=SAM::add(s[i]-'a');
	for(int i=2;i<=SAM::sz;i++)e[SAM::fa[i]].pb(i);
	dfs(1);
	int cur=0,ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+1;
		while(!chk(i)){
			dp[i]--;cur++;
			T.mdf(1,1,cnt,dfn[pos[cur]],dp[cur]);
		}
		chkmx(ans,dp[i]);
	}
	writeln(ans);
	cerr<<"sto luogu";
}