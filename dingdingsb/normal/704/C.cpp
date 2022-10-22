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
const int mod=1e9+7;
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
const int N=2e5+100;
int n,m;bool vis[N];
int k[N],x[N],y[N],deg[N];vector<int>id[N];
int e[N];vector<bool>now;int ed;
int gt(int i){return i<=n?x[i]:y[i-n];}
void dfs(int u){
	ed=(u-(u>n)*n);vis[u]=1;
	if(u<=n)u+=n;else u-=n;vis[u]=1;
	if(e[u]){
		now.pb(gt(u)!=gt(e[u]));
		if(e[u]&&!vis[e[u]])dfs(e[u]);
	}
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		read(k[i],x[i]);if(k[i]==2)read(y[i]);
		if(x[i]==y[i])k[i]=1,y[i]=0;
		id[abs(x[i])].pb(i);
		id[abs(y[i])].pb(i+n);
		vis[abs(x[i])]=vis[abs(y[i])]=1;
		if(x[i]<0)x[i]=m-x[i];
		if(y[i]<0)y[i]=m-y[i];
	}
	mint res0=1,res1=0;
	for(int i=1;i<=m;i++)if(!vis[i])res0*=2;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;i++)if(id[i].size()==2u)
		deg[id[i][0]]++,deg[id[i][1]]++,e[id[i][0]]=id[i][1],e[id[i][1]]=id[i][0];
	for(int i=1;i<=n;i++)if(!vis[i]){
		if(!e[i]&&!e[i+n]){
			vis[i]=1;
			if(k[i]==1)tie(res0,res1)=mp(res0+res1,res0+res1);
			else tie(res0,res1)=mp(res0+res1*3,res0*3+res1);
		}else if(e[i]==i+n){
			vis[i]=1;
			if(x[i]==y[i])tie(res0,res1)=mp(res0+res1,res0+res1);
			else tie(res0,res1)=mp(res1+res1,res0+res0);
		}else if(deg[i]+deg[i+n]<=1){
			//
			//12
			static mint dp[2][2][2];memset(dp,0,sizeof dp);
			int cur=0,lst=1;
			if(k[i]==1){
				now.clear();
				dfs(i+n);
				dp[cur][0][0]=dp[cur][1][1]=1;
			}else{
				now.clear();
				if(deg[i]==0)dfs(i);
				else dfs(i+n);
				dp[cur][0][0]=1,dp[cur][0][1]=1,dp[cur][1][1]=2;
			}
			for(auto g:now){
				swap(cur,lst);memset(dp[cur],0,sizeof dp[cur]);
				for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)
					// j-(j^g) i
					dp[cur][i][k^((j^g)|i)]+=dp[lst][j][k]; 
			}
			mint now0=0,now1=0;
			if(k[ed]==1)now0=dp[cur][0][0],now1=dp[cur][0][1];
			else now0=dp[cur][0][0]+dp[cur][1][0],now1=dp[cur][0][1]+dp[cur][1][1];
			tie(res0,res1)=mp(res0*now0+res1*now1,res0*now1+res1*now0);
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		now.clear();dfs(i);
		static mint dp[2][2][2];
		bool a=now.back();now.pop_back();
		mint now0=0,now1=0;
		for(int st=0;st<2;st++){
			memset(dp,0,sizeof dp);int cur=0,lst=1;
			for(int i=0;i<2;i++)dp[cur][i][st|i]=1;
			for(auto g:now){
				swap(cur,lst);memset(dp[cur],0,sizeof dp[cur]);
				for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)
					dp[cur][i][k^((j^g)|i)]+=dp[lst][j][k];
			}
			now0+=dp[cur][st^a][0],now1+=dp[cur][st^a][1];
		}
		tie(res0,res1)=mp(res0*now0+res1*now1,res0*now1+res1*now0);
	}
	writeln(res1.x);
}