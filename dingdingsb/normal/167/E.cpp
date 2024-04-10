// Problem: CF167E Wizards and Bets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF167E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
const int N=610;
int n,m,mod;
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
    modint &operator++(int){return *this+=1;}
};
vector<int>e[N];
int a[N],cnt1;
int b[N],cnt2;
int in[N],out[N];
modint mat[N][N],f[N][N];
bool vis[N];
void dfs(int u){
	if(vis[u])return;vis[u]=1;
	if(!out[u])f[u][u]=1;
	for(auto v:e[u]){
		dfs(v);
		for(int j=1;j<=cnt2;j++)
			f[u][b[j]]+=f[v][b[j]];
	}
}
modint det(modint a[N][N],int n){
	modint res=1;
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=i+1;j<=n;j++)
			if(a[j][i]!=0)k=j;
		if(k!=i)swap(a[k],a[i]),res=-res;res*=a[i][i];
		for(int j=i+1;j<=n;j++){
			if(!a[j][i].x)continue;
			modint inv=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++)
				a[j][k]-=inv*a[i][k];
		}
	}return res;
}
signed main(){
	read(n,m,mod);
	for(int i=1;i<=m;i++){
		int u,v;read(u,v);
		e[u].push_back(v);
		out[u]++;in[v]++;
	}
	for(int i=1;i<=n;i++)
		!in[i]&&(a[++cnt1]=i),!out[i]&&(b[++cnt2]=i);
	for(int i=1;i<=n;i++)dfs(i);
	for(int i=1;i<=cnt1;i++)
		for(int j=1;j<=cnt2;j++)
			mat[i][j]=f[a[i]][b[j]];
	write(det(mat,cnt1).x);
}