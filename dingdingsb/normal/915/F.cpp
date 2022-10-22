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
#define int ll
#define lowbit(x) ((x)&-(x))
const int N=1e6+100;
int n,a[N];
pair<int,pair<int,int>>e[N];
int fa[N],sz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	sz[y]+=sz[x];fa[x]=y;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<n;i++)
		read(e[i].se.se,e[i].se.fi);
	
	ll ans=0;
	for(int i=1;i<n;i++)e[i].fi=max(a[e[i].se.fi],a[e[i].se.se]);
	sort(e+1,e+n);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++)
		ans+=e[i].fi*sz[find(e[i].se.fi)]*sz[find(e[i].se.se)],
		merge(e[i].se.fi,e[i].se.se);
	
	for(int i=1;i<n;i++)e[i].fi=min(a[e[i].se.fi],a[e[i].se.se]);
	sort(e+1,e+n);
	reverse(e+1,e+n);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++)
		ans-=e[i].fi*sz[find(e[i].se.fi)]*sz[find(e[i].se.se)],
		merge(e[i].se.fi,e[i].se.se);
	write(ans);
}