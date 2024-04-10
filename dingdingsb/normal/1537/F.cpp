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
const int N=210000;
int T,n,m,v[N],t[N];vector<int>e[N];
int col[N];ll ini[2],tar[2];
bool flag;
void dfs(int u){
	ini[col[u]]+=v[u];
	tar[col[u]]+=t[u];
	for(auto v:e[u]){
		if(col[v]==-1){
			col[v]=col[u]^1;
			dfs(v);
		}else{
			if(col[v]!=col[u]^1)
				flag=0;
			//
		}
	}
}
signed main(){
	read(T);
	while(T--){
		read(n,m);
		for(int i=1;i<=n;i++)e[i].clear(),col[i]=-1;
		for(int i=1;i<=n;i++)read(v[i]);
		for(int i=1;i<=n;i++)read(t[i]);
		for(int i=1,u,v;i<=m;i++)
			read(u,v),e[u].pb(v),e[v].pb(u);
		bool ans=1;
		for(int i=1;i<=n;i++)if(col[i]==-1){
			col[i]=0;tar[0]=tar[1]=0;ini[0]=ini[1]=0;
			flag=1;dfs(i);
			if(!flag){
				if((tar[0]+tar[1]-ini[0]-ini[1])%2==0);
				else ans=0;
			}else{
				if(tar[0]-ini[0]==tar[1]-ini[1]);
				else ans=0;
			}
		}
		puts(ans?"YES":"NO");
	}
}