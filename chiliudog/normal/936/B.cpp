#include<bits/stdc++.h>
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
/******************************head*******************************/
const int maxn=100005;
int num,head[maxn],t[maxn<<1],ne[maxn<<1];
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
}
int S[maxn],top,dfn[maxn],low[maxn],tme;
bool vis[maxn],ins[maxn],nb[maxn];
inline void tarjan(int x){
	dfn[x]=low[x]=++tme;S[++top]=x;vis[x]=ins[x]=1;
	forE(i,x)if(!vis[t[i]]){
		tarjan(t[i]);low[x]=min(low[x],low[t[i]]);
	}else if (ins[t[i]]){
		low[x]=min(low[x],dfn[t[i]]);
	}
	if(low[x]==dfn[x]){
		bool res=0;
		if(S[top]==x)nb[x]=res=0;else nb[x]=res=1;
		while(S[top]!=x){
			nb[S[top]]=res;
			ins[S[top]]=0;top--;
		}ins[x]=0;top--;
	}
}
bool rec[maxn][2],draw;
int n,m,d[maxn];
vector<int> ans;
inline bool dfs(int x,int p){
	if(rec[x][p])return 0;rec[x][p]=1;
	if(nb[x])draw=1;
	if((p==1)&&(d[x]==0)){
		ans.pb(x);
		return 1;
	}
	forE(i,x){
		if(dfs(t[i],p^1)){
			ans.pb(x);
			return 1;
		}
	}return 0;
}
int main(){
	// judge();
	read(n);read(m);
	rep(i,1,n)head[i]=-1;
	rep(i,1,n){
		read(d[i]);
		rep(j,1,d[i]){
			int x;read(x);
			addedge(i,x);
		}
	}int s;read(s);
	tarjan(s);
	// cerr<<nb[1]<<endl;
	if(dfs(s,0)){
		puts("Win");
		reverse(ans.begin(),ans.end());
		for(u32 i=0;i<ans.size();i++)printf("%d ",ans[i]);
		return 0;
	}
	if(draw){
		puts("Draw");
		return 0;
	}
	puts("Lose");

	return 0;
}