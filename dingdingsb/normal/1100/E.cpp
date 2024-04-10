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
const int N=1e5+100;
int n,m;
int u[N],v[N],w[N];
vector<pair<int,int>>e[N];
int deg[N],id[N];
bool topo(int mid){
	int cnt=0;
	memset(deg,0,sizeof deg);
	for(int u=1;u<=n;u++)
		for(auto E:e[u])if(E.se>mid)
			deg[E.fi]++;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(deg[i]==0)q.push(i);
	while(q.size()){
		int u=q.front();q.pop();
		id[u]=++cnt;
		for(auto E:e[u])if(E.se>mid)
			if(!--deg[E.fi])q.push(E.fi);
	}
	return cnt==n;
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++)
		read(u[i],v[i],w[i]),e[u[i]].pb(mp(v[i],w[i]));
	int l=0,r=1e9+1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(topo(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	topo(ans);
	vector<int>kk;
	for(int i=1;i<=m;i++)if(w[i]<=ans)
		if(id[u[i]]>id[v[i]])
			kk.pb(i);
	writeln(ans,kk.size());
	for(auto x:kk)write(x),pc(' ');
}