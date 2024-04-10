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
const int N=4e5+1000,M=19,B=700;
namespace SAM{
	int ch[N][27],len[N],fa[N],sz=1,lst=1;
	int ins(int c){
		int cur=++sz,p=lst;
		len[cur]=len[lst]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=cur;
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
using SAM::sz;
int n,m,st[N],ed[N],length[N],now,pos[N],rev[N],lid[N],lcnt,tar[N];char s[N];
ll res,ans[N];vector<pair<int,int>>qry[N];
struct DS{
	//O(n) O(1) 
	int L[N],R[N],bel[N];
	ll s[N],S[N];
	DS(){
		for(int l=1,r=B,i=1;l<N;l+=B,r+=B,i++){
			chkmn(r,N-1);
			L[i]=l,R[i]=r;
			for(int j=l;j<=r;j++)
				bel[j]=i;
		}
	}
	void add(int x,int y){
		for(int i=x;i<=R[bel[x]];i++)s[i]+=y;
		for(int i=bel[x];i<=bel[N-1];i++)S[i]+=y;
	}
	void add(int l,int r,int y){add(l,y);add(r+1,-y);}
	ll qry(int x){return s[x]+S[bel[x]-1];}
}T;
vector<int>e[N];int dfin[N],dfout[N],cnt,fa[N][M];
int coef[N];
void dfs(int u){
	dfin[u]=++cnt;
	for(int i=1;i<M;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		fa[v][0]=u;
		dfs(v);
	}
	dfout[u]=cnt;
}
void calc(int u,int id){
	coef[u]=0;
	for(auto v:e[u])calc(v,id),coef[u]+=coef[v];
	if(lid[rev[u]]==id)coef[u]++;
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);length[i]=strlen(s+1);
		st[i]=now+1;
		for(int j=1;j<=length[i];j++)
			rev[pos[++now]=SAM::ins(s[j]-'a')]=i;
		ed[i]=now;
		if(length[i]>=B)lid[i]=++lcnt;
		SAM::ins(26);
	}
	for(int i=2;i<=sz;i++)e[SAM::fa[i]].pb(i);
	for(int i=1,l,r,k;i<=m;i++){
		read(l,r,k);
		qry[l-1].eb(k,-i);
		qry[r].eb(k,i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		int u=pos[ed[i]];
		for(int j=M-1;~j;j--)if(len[fa[u][j]]>=length[i])u=fa[u][j];
		tar[i]=u;
	}
	for(int i=1;i<=n;i++){
		T.add(dfin[tar[i]],dfout[tar[i]],1);
		for(auto wyh:qry[i]){
			int k,id,op=1;tie(k,id)=wyh;
			if(id<0)id=-id,op=-1;
			if(!lid[k])for(int j=st[k];j<=ed[k];j++)ans[id]+=op*T.qry(dfin[pos[j]]);
		}
	}
	//>=B
	for(int now=1;now<=lcnt;now++){
		res=0;calc(1,now);
		for(int i=1;i<=n;i++){
			res+=coef[tar[i]];
			for(auto wyh:qry[i]){
				int k,id,op=1;tie(k,id)=wyh;
				if(id<0)id=-id,op=-1;
				if(lid[k]==now)ans[id]+=op*res;
			}
		}
	}
	for(int i=1;i<=m;i++)writeln(ans[i]);
	
}