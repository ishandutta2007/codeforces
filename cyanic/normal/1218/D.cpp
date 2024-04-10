#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int mod=1e9+7,mod2=23332333;
const int N=(1<<17)+5;
int f[N],g[N],F[N],G[N],d[N],vis[N],fa[N],fw[N];
int n,m,u,v,w,tot;
vector<pii> e[N];

inline int fix(int x){
	return x>=mod?x-mod:x;
}
inline int fix2(int x){
	return x>=mod2?x-mod2:x;
}
inline int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

void fwt(int a[N],int n){
	for(int k=0,d=1;k<n;k++,d<<=1)
		for(int i=0;i<(1<<n);i+=d<<1){
			int *l=a+i,*r=a+i+d,x,y;
			REP(j,d)
				x=fix(*l+*r),y=fix(*l+mod-*r),
				*(l++)=x,*(r++)=y;
		}
}
void fwt2(int a[N],int n){
	for(int k=0,d=1;k<n;k++,d<<=1)
		for(int i=0;i<(1<<n);i+=d<<1){
			int *l=a+i,*r=a+i+d,x,y;
			REP(j,d)
				x=fix2(*l+*r),y=fix2(*l+mod2-*r),
				*(l++)=x,*(r++)=y;
		}
}

void dfs(int u){
	vis[u]=1;
	int flag=1;
	for(auto v:e[u]){
		if(flag&&v.fi==fa[u]&&v.se==fw[u]){
			flag=0;
			continue;
		}
		if(!vis[v.fi]){
			fa[v.fi]=u;
			fw[v.fi]=v.se;
			d[v.fi]=d[u]+1;
			dfs(v.fi);
		}
		else if(d[v.fi]<d[u]){
			memset(g,0,sizeof g);
			memset(G,0,sizeof G);
			int x=u;
			while(x!=v.fi){
				g[fw[x]]++;
				G[fw[x]]++;
				x=fa[x];
			}
			g[v.se]++;
			G[v.se]++;
			fwt(g,17);
			fwt2(G,17);
			REP(s,1<<17)f[s]=(ll)f[s]*g[s]%mod;
			REP(s,1<<17)F[s]=(ll)F[s]*G[s]%mod2;
		}
	}
}

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(u),read(v),read(w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
		tot^=w;
	}
	f[0]=1;
	F[0]=1;
	fwt(f,17);
	fwt2(F,17);
	dfs(1);
	fwt(f,17);
	fwt2(F,17);
	int inv=power(1<<17,mod-2);
	REP(s,1<<17)f[s]=(ll)f[s]*inv%mod;
	REP(s,1<<17)
		if(f[s^tot]||F[s^tot]){
			printf("%d %d\n",s,f[s^tot]);
			break;
		}
	return 0;
}