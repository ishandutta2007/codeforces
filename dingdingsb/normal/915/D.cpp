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
const int N=510;
int n,m;vector<int>e[N];
int deg[N],tmp[N];
bool topo(){
	queue<int>q;int cnt=0;
	for(int i=1;i<=n;i++)if(deg[i]==0)q.push(i);
	while(q.size()){
		int u=q.front();q.pop();cnt++;
		for(auto v:e[u]){
			deg[v]--;
			if(deg[v]==0)q.push(v);
		}
	}
	return cnt==n;
}
signed main(){
	read(n,m);
	for(int i=1,u,v;i<=m;i++)
		read(u,v),e[u].pb(v),tmp[v]++;
	memcpy(deg,tmp,sizeof deg);
	if(topo())return puts("YES"),0;
	for(int i=1;i<=n;i++)if(tmp[i]){
		memcpy(deg,tmp,sizeof deg);
		deg[i]--;
		if(topo())return puts("YES"),0;
	}
	puts("NO");
}