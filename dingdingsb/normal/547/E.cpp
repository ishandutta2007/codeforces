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
const int N=8e5+100,M=19;
namespace SAM{
	int ch[N][27],fa[N],len[N],sz=1,lst=1;
	int ins(int c){
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
using SAM::sz;
using SAM::len;
int n,q,cnt,l[N],ed[N],pos[N];char s[N];
int fa[N][M],dfin[N],dfout[N];vector<int>e[N];
int ans[N];vector<pair<int,int>>qry[N];// fi se/-se
struct BIT{
	int tree[N];
	void add(int x,int v){for(;x<=sz;x+=lowbit(x))tree[x]+=v;}
	int qry(int x){int res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
	int qry(int l,int r){return qry(r)-qry(l-1);}
}T;
void dfs(int u){
	for(int i=1;i<M;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	dfin[u]=++cnt;
	for(auto v:e[u])fa[v][0]=u,dfs(v);
	dfout[u]=cnt;
}
signed main(){
	//freopen("1.in","r",stdin);
	read(n,q);int now=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		l[i]=strlen(s+1);
		for(int j=1;j<=l[i];j++)
			pos[++now]=SAM::ins(s[j]-'a');
		ed[i]=now;SAM::ins(26);
	}
	for(int i=2;i<=sz;i++)e[SAM::fa[i]].pb(i);
	dfs(1);
	for(int i=1;i<=q;i++){
		int l,r,k;read(l,r,k);
		int u=pos[ed[k]];
		for(int j=M-1;~j;j--)if(len[fa[u][j]]>=::l[k])u=fa[u][j];
		qry[ed[l-1]].eb(u,-i);
		qry[ed[r]].eb(u,i);
	}
	for(int i=1;i<=now;i++){
		T.add(dfin[pos[i]],1);
		for(auto Q:qry[i]){
			int u,id;tie(u,id)=Q;
			if(id>0)ans[id]+=T.qry(dfin[u],dfout[u]);
			else ans[-id]-=T.qry(dfin[u],dfout[u]);
		}
	}
	for(int i=1;i<=q;i++)writeln(ans[i]);
}