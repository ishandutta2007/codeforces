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
int mod;
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
const int N=3e2+10;
int n,m;char s[N][N];
struct DSU{
	int fa[N*N];
	DSU(){iota(fa+1,fa+N*N,1);}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){x=find(x),y=find(y);fa[x]=y;}
}D;
int id[N][N],cnt;
struct mat{
	mint a[N][N];
	void init(){memset(a,0,sizeof a);}
	mint*operator[](int x){return a[x];}
	void adde(int u,int v){
		//writeln(u,v);
		a[u][v]-=1,a[v][u]-=1;
		a[u][u]+=1,a[v][v]+=1;
	}
	mint det(int n){
		mint ans=1;
		for(int i=1;i<=n;i++){
			for(int p=i+1;p<=n;p++)if(a[p][i].x)
				{swap(a[i],a[p]),ans=0-ans;break;}
			if(!a[i][i].x)return 0;
			ans*=a[i][i];
			for(int j=i+1;j<=n;j++){
				mint inv=a[j][i]/a[i][i];
				for(int k=i;k<=n;k++)
					a[j][k]-=a[i][k]*inv;
			}
		}
		return ans;
	}
}M[2];
int tag[N*N],lst[N][N],tot[2];
signed main(){
	read(n,m,mod);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			id[i][j]=++cnt;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)if(s[i][j]!='*'){
			if(s[i][j]=='\\'){
				if(D.find(id[i-1][j-1])==D.find(id[i][j]))return puts("0"),0;
				D.merge(id[i-1][j-1],id[i][j]);
			}else{
				if(D.find(id[i-1][j])==D.find(id[i][j-1]))return puts("0"),0;
				D.merge(id[i-1][j],id[i][j-1]);
			}
		}
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(D.fa[id[i][j]]==id[i][j])
				tag[id[i][j]]=++tot[(i+j)&1];
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)lst[i][j]=tag[D.find(id[i][j])];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='*'){
		M[(i+j)&1].adde(lst[i-1][j-1],lst[i][j]);
		M[(i+j)&1^1].adde(lst[i][j-1],lst[i-1][j]);
	}
	mint ans=0;
	ans+=M[0].det(tot[0]-1);
	ans+=M[1].det(tot[1]-1);
	writeln(ans.x);
}