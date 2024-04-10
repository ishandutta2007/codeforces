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
const int N=1e6+100;
int n,m,k;vector<int>e[N];
int cnt,sum;ll s;bool vis[N];
void dfs(int u){
	sum+=(vis[u]=1);
	for(auto v:e[u])if(!vis[v])
		dfs(v);
}
signed main(){
	read(n,m,k);
	for(int i=1,u,v;i<=m;i++)
		read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)if(!vis[i])
		sum=0,dfs(i),cnt++,s+=min(sum,k);
	if(k==1)write(max(0,cnt-2));
	else if(cnt==1)write(0);
	else write(max(0ll,cnt-1-s/2));
}