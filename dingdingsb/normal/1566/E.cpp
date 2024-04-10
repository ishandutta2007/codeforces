#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=2e5+100;
int t,n,k,f[N];
vector<int>e[N];
//f[i] = 1  0 
void dfs(int u,int fa){
	int res=0;
	for(auto v:e[u])if(v!=fa){
		dfs(v,u);
		res+=f[v];
	}
	if(fa){
		if(res)f[u]=0,k++;
		else f[u]=1;
	}
} 
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++)
			read(u,v),e[u].pb(v),e[v].pb(u);
		k=0;
		dfs(1,0);
		for(auto v:e[1])if(f[v]){
			write(n-k-1-k);
			goto loop;
		}
		write(n-k-1-(k-1));
		loop:;
		putchar('\n');
	}
}