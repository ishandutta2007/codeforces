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
const int N=2e6+100;
int sz=1,lst=1,ch[N][26],fa[N],len[N];
int cnt[N],id[N];
void add(int c){
	int cur=++sz,p=lst;
	len[cur]=len[lst]+1;cnt[cur]=1;
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
	lst=cur;
}
int n,m;vector<int>e[N];
void dfs(int u){for(auto v:e[u])dfs(v),cnt[u]+=cnt[v];}
int u,l;ll ans=0;
void ADD(int c){while(u&&!ch[u][c])l=len[u=fa[u]];if(ch[u][c]){l++;u=ch[u][c];}}
void DEL(){if(l==m&&--l==len[fa[u]])u=fa[u];}
void calc(){if(l==m&&id[u]!=n){id[u]=n;ans+=cnt[u];}}
char s[N];
signed main(){
	memset(id,0xff,sizeof id);
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)add(s[i]-'a');
	for(int i=2;i<=sz;i++)e[fa[i]].pb(i);
	dfs(1);
	read(n);
	while(n--){
		scanf("%s",s+1);m=strlen(s+1);
		u=1,l=0,ans=0;
		for(int i=1;i<=m;i++)ADD(s[i]-'a');
		calc();
		for(int i=1;i<m;i++)DEL(),ADD(s[i]-'a'),calc();
		writeln(ans);
	}
}