#include<bits/stdc++.h>
#define mp make_pair
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
#define lowbit(x) ((x)&-(x))
const int N=1e6+110,M=20;
int n,fa[N][M],dep[N];
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=M-1;~i;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)return u;
	for(int i=M-1;~i;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
tuple<int,int,int>d={2,2,3};
void add(int x,int y){
	fa[y][0]=x;dep[y]=dep[x]+1;
	for(int i=1;i<M;i++)
		fa[y][i]=fa[fa[y][i-1]][i-1];
	auto tmp=d;
	chkmx(d,make_tuple(dis(get<1>(tmp),y),get<1>(tmp),y));
	chkmx(d,make_tuple(dis(get<2>(tmp),y),get<2>(tmp),y));
}
signed main(){
	//freopen("1.in","r",stdin);
	read(n);
	fa[2][0]=fa[3][0]=fa[4][0]=1;
	dep[1]=1;dep[2]=dep[3]=dep[4]=2;
	for(int i=1,u;i<=n;i++){
		read(u);add(u,2*i+3);add(u,2*i+4);
		writeln(get<0>(d));
	}
}