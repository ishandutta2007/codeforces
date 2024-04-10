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
const int N=210,M=10;
int n;vector<int>e[N];
int fa[N][M],dep[N];
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
    modint<mod> &operator++(int){return *this+=1;}
};
using mint=modint<1000000007>;
mint f[N][N];
void dfs(int u,int fath){
	fa[u][0]=fath;dep[u]=dep[fath]+1;
	for(int j=1;j<M;j++)
		fa[u][j]=fa[fa[u][j-1]][j-1];
	for(auto v:e[u])if(v!=fath)
		dfs(v,u);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=M-1;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=M-1;~i;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
mint calc(int rt){
	dfs(rt,0);
	mint res=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++){
			int LCA=lca(i,j);
			res+=f[dep[i]-dep[LCA]][dep[j]-dep[LCA]];
		}
	return res;
}
signed main(){
	read(n);
	for(int i=1,u,v;i<n;i++)
		read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)f[0][i]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f[i][j]=(f[i][j-1]+f[i-1][j])/2;
	mint ans=0;
	for(int i=1;i<=n;i++)ans+=calc(i);
	write((ans/n).x);
}