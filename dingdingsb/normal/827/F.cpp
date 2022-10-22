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
const int N=5e5+100;
struct node{
	int u,v,l,r;
	node(int u,int v,int l,int r):u(u),v(v),l(l),r(r){}
	bool operator<(const node rhs)const{
		return l<rhs.l;
	}
	bool operator>(const node rhs)const{
		return l>rhs.l;
	}
};
int n,m;
priority_queue<node,vector<node>,greater<node>>edges;
vector<pair<int,int>>e[N][2];
int f[N][2];
void solve(int u,int v,int l,int r){
	int op=l&1;
	if(f[u][op]>=l){
		if(v==n)write(l+1),exit(0);
		if(f[v][op^1]<r+1){
			f[v][op^1]=r+1;
			for(auto E:e[v][op^1])
				edges.push(node(v,E.fi,l+1,E.se));
			e[v][op^1].clear();
		}
	}else e[u][op].eb(v,r);
}
signed main(){
	read(n,m);
	if(n==1)return puts("0"),0;
	for(int i=1,u,v,l,r;i<=m;i++){
		read(u,v,l,r);r--;
		int op=r-l&1;
		edges.push(node(u,v,l,r-op));
		edges.push(node(v,u,l,r-op));
		edges.push(node(u,v,l+1,r-(op^1)));
		edges.push(node(v,u,l+1,r-(op^1)));
	}
	memset(f,-0x3f,sizeof f);f[1][0]=0;
	while(edges.size()){
		node E=edges.top();edges.pop();
		if(E.l>E.r)continue;
		solve(E.u,E.v,E.l,E.r);
	}
	puts("-1");
	cerr<<"sto emptyhope";
}