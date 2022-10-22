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
const int N=4e5+100;
namespace SGT{
	// 
	struct node{
		int lc,rc;
	}t[N<<5];
	int cnt;
	int build(int l,int r,int p){
		int x=++cnt;
		if(l==r)return x;
		if(p<=mid)t[x].lc=build(l,mid,p);
		else t[x].rc=build(mid+1,r,p);
		return x;
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y)return x+y;
		int o=++cnt;
		if(l==r){
			return o;
		}else{
			t[o].lc=merge(t[x].lc,t[y].lc,l,mid);
			t[o].rc=merge(t[x].rc,t[y].rc,mid+1,r);
			return o;
		}
	}
	bool qry(int x,int l,int r,int ql,int qr){
		if(!x)return 0;
		if(r<ql||qr<l)return 0;
		if(ql<=l&&r<=qr)return 1;
		return qry(t[x].lc,l,mid,ql,qr)||qry(t[x].rc,mid+1,r,ql,qr);
	}
}
namespace SAM{
	int ch[N][26],fa[N],len[N],sz=1,lst=1;
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
				memcpy(ch[nw],ch[q],sizeof ch[q]);
				for(;ch[p][c]==q;p=fa[p])
					ch[p][c]=nw;
				fa[cur]=fa[q]=nw;
			}
		}
		return lst=cur;
	}
}
using SAM::len;
using SAM::sz;
using SAM::fa;
int n,dp[N],fr[N],rt[N],pos[N];char s[N];
vector<int>e[N];
void dfs1(int u){
	for(auto v:e[u]){
		dfs1(v);
		rt[u]=SGT::merge(rt[u],rt[v],1,n);
		if(!pos[u])pos[u]=pos[v];
	}
}
void dfs2(int u){
	for(auto v:e[u]){
		if(u==1)dp[v]=1,fr[v]=v;
		else{
			if(SGT::qry(rt[fr[u]],1,n,pos[v]-len[v]+len[fr[u]],pos[v]-1))
				dp[v]=dp[u]+1,fr[v]=v;
			else dp[v]=dp[u],fr[v]=fr[u];
		}
		dfs2(v);
	}
}
signed main(){
	read(n);scanf("%s",s+1);
	for(int i=1;i<=n;i++)SAM::add(s[i]-'a'),rt[SAM::lst]=SGT::build(1,n,i),pos[SAM::lst]=i;
	for(int i=2;i<=sz;i++)e[fa[i]].pb(i);
	dfs1(1);dfs2(1);
	int ans=0;for(int i=1;i<=sz;i++)chkmx(ans,dp[i]);
	writeln(ans);
}