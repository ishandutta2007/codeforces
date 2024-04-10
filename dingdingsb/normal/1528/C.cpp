#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=3e5+100;
int n;
namespace Tree2{
	vector<int>e[N];
	int dfn[N],sz[N],cnt;
	void dfs(int u){
		dfn[u]=++cnt;sz[u]=1;
		for(auto v:e[u])dfs(v),sz[u]+=sz[v];
	}
	void init(){
		cnt=0;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=2,x;i<=n;i++)
			read(x),e[x].pb(i);
		dfs(1);
	}
}
using Tree2::sz;
using Tree2::dfn;
int t,ans;
vector<int>e[N];
set<pair<int,int>>s1;//
int r[N];//
void dfs(int u){
	int l=dfn[u],r=::r[l];
	int L=-1,tmp;
	if(s1.size()==0){
		s1.insert(mp(l,r));
		tmp=0;
		//tmp=0 
	}else{
		//
		if(s1.upper_bound(mp(l,0x3f3f3f3f))!=s1.begin()&&l<=(--s1.upper_bound(mp(l,0x3f3f3f3f)))->second){
			tmp=1;L=(--s1.upper_bound(mp(l,0x3f3f3f3f)))->first;
			s1.erase(mp(L,::r[L]));
			s1.insert(mp(l,r));
			tmp=1;
			//tmp=1  [L,r[L]] 
		}
		else if(s1.lower_bound(mp(l,0))!=s1.end()&&s1.lower_bound(mp(l,0))->first<=r){
			tmp=2;
			//tmp=2
		}else{
			s1.insert(mp(l,r));
			tmp=0;
		}
	}
	chkmx(ans,(int)s1.size());
	for(auto v:e[u])dfs(v);
	if(tmp==0)s1.erase(mp(l,r));
	if(tmp==1)s1.erase(mp(l,r)),s1.insert(mp(L,::r[L]));
}
void solve(){
	read(n);
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=2,x;i<=n;i++)
		read(x),e[x].pb(i);
	Tree2::init();
	for(int i=1;i<=n;i++)r[dfn[i]]=dfn[i]+sz[i]-1;
	ans=0;dfs(1);write(ans);putchar('\n');
}
signed main(){
	read(t);while(t--)solve();
}