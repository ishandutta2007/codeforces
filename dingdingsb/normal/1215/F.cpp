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
const int N=2e6+10;
int n,p,mx,m,l[N],r[N],cnt;
vector<int>e[N];
int pos[N],ind1[N],ind2[N];
int dfn[N],low[N],col[N],tot,colcnt;
stack<int>s;bool ins[N];
void dfs(int u){
	s.push(u);dfn[u]=low[u]=++tot;ins[u]=1;
	for(auto v:e[u])
		if(!dfn[v])dfs(v),chkmn(low[u],low[v]);
		else if(ins[v])chkmn(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		int x=0;++colcnt;
		do{
			x=s.top();s.pop();
			col[x]=colcnt;ins[x]=0;
		}while(x!=u);
	}
}
signed main(){
	read(n,p,mx,m);cnt=2*p;
	for(int i=1,x,y;i<=n;i++)read(x,y),e[x+p].pb(y),e[y+p].pb(x);
	for(int i=1;i<=p;i++)read(l[i],r[i]),pos[i]=i;
	for(int i=1,x,y;i<=m;i++)read(x,y),e[x].pb(y+p),e[y].pb(x+p);
	sort(pos+1,pos+1+p,[&](int i,int j){return l[i]<l[j];});
	ind1[p]=pos[p]+p;ind2[p]=pos[p];
	for(int i=p-1;i;i--)
		ind1[i]=++cnt,e[ind1[i]].pb(ind1[i+1]),e[ind1[i]].pb(pos[i]+p),
		ind2[i]=++cnt,e[ind2[i+1]].pb(ind2[i]),e[pos[i]].pb(ind2[i]);
	for(int i=1;i<=p;i++){
		int j=lower_bound(pos+1,pos+1+p,r[i]+1,[&](int a,int b){return l[a]<b;})-pos;
		if(j<=p)e[i].pb(ind1[j]),e[ind2[j]].pb(i+p);
	}
	for(int i=1;i<=cnt;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=p;i++)if(col[i]==col[i+p])return writeln(-1),0;
	vector<int>res;int mxl=0;
	for(int i=1;i<=p;i++)if(col[i]<col[i+p])res.pb(i),chkmx(mxl,l[i]);
	writeln(res.size(),mxl);
	for(auto x:res)write(x),pc(' ');
	cerr<<"30s"<<endl;
	cerr<<"luogubotcf"<<endl;
}