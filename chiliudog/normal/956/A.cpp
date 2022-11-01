#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=105;
char s[maxn][maxn];
bool vis[maxn];
int num,head[maxn],t[maxn*maxn<<1],ne[maxn*maxn<<1],n,m;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
vector<int> curx,cury;
inline void dfs(int x){
	vis[x]=1;
	if(x<=n){
		curx.pb(x);
	}else{
		cury.pb(x-n);
	}
	forE(i,x)if(!vis[t[i]]){
		dfs(t[i]);
	}
}
inline void solve(){
	read(n);read(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n+m)head[i]=-1;
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='#')addedge(i,j+n);
	rep(i,1,n){
		if(vis[i])continue;
		curx.clear();cury.clear();
		dfs(i);
		for(int v1:curx)for(int v2:cury){
			if(s[v1][v2]!='#'){
				puts("No");
				return;
			}
		}
	}
	rep(i,1,m){
		if(vis[i+n])continue;
		curx.clear();cury.clear();
		dfs(i+n);
		for(int v1:curx)for(int v2:cury){
			if(s[v1][v2]!='#'){
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
int main(){
	solve();	
	return 0;
}