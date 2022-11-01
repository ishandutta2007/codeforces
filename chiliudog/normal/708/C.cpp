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
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
const int maxn=400005;
int ffa[maxn],dp[maxn],num,head[maxn],t[maxn<<1],size[maxn],ne[maxn<<1],n;
vector<pin> son[maxn];
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline void dfs(int x,int fa){
	size[x]=1;
	forE(i,x)if(t[i]!=fa){ffa[t[i]]=x;
		dp[t[i]]=dp[x]+1;dfs(t[i],x);son[x].pb(mk(size[t[i]],t[i]));
		size[x]+=size[t[i]];
	}if(fa!=-1)son[x].pb(mk(n-size[x],fa));sort(son[x].begin(),son[x].end());
}bool ans[maxn];
inline void calc(int x,int fa,int bl,int C,int ts){
	int tot=son[C].size(),v=0;
	if(son[C][tot-1].w2==bl){v=son[C][tot-2].w1;}else {v=son[C][tot-1].w1;}
//	dg("%d %d\n",x,v);
	if(n-ts<=n/2)v=max(v,n-ts);
	if(son[x][(int)son[x].size()-1].w1<=n/2){
		ans[x]=1;
	}else{
		if(son[x][(int)son[x].size()-1].w1-v<=n/2)
			ans[x]=1;
	}
	forE(i,x)if(t[i]!=fa)calc(t[i],x,bl,C,ts);
}
int main(){
	read(n);rep(i,1,n)head[i]=-1;
	if(n==2){
		puts("1 1");
		return 0;
	}
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		addedge(x,y);
	}
	dfs(1,-1);int x=0;
	rep(i,1,n)if(size[i]>n/2&&dp[i]>=dp[x])x=i;
	ans[x]=1;
	for(pin t:son[x])calc(t.w2,x,t.w2,x,t.w1);
	rep(i,1,n)printf("%d ",(int)ans[i]);
	return 0;
}