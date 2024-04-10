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
/*******************************head*******************************/
const int maxn=200005;	
int head[maxn],t[maxn<<1],ne[maxn<<1],num;
int rd[maxn],low[maxn],sz[maxn],dfn[maxn],bl[maxn],S[maxn],top,vis[maxn],ins[maxn],tme,block;
inline void addedge(int x,int y){
	// cerr<<x<<' '<<y<<endl;
	ne[++num]=head[x];head[x]=num;t[num]=y;
}
inline void tarjan(int x){
	low[x]=dfn[x]=++tme;S[++top]=x;vis[x]=ins[x]=1;
	forE(i,x)if(!vis[t[i]]){
		tarjan(t[i]);low[x]=min(low[x],low[t[i]]);
	}else if (ins[t[i]]){
		low[x]=min(low[x],dfn[t[i]]);
	}
	if(low[x]==dfn[x]){
		block++;
		while(S[top]!=x){
			bl[S[top]]=block;ins[S[top]]=0;top--;sz[block]++;
		}bl[S[top]]=block;ins[S[top]]=0;top--;sz[block]++;
	}
}
int u[maxn],c[maxn][2],n,m,h;
int main(){
	read(n);read(m);read(h);
	rep(i,1,n){
		read(u[i]);
	}
	rep(i,1,m)read(c[i][0]),read(c[i][1]);
	rep(i,1,n)head[i]=-1;
	rep(i,1,m){
		if((u[c[i][0]]+1)%h==u[c[i][1]])
			addedge(c[i][0],c[i][1]);
		if((u[c[i][1]]+1)%h==u[c[i][0]])
			addedge(c[i][1],c[i][0]);
	}
	rep(i,1,n)if(!vis[i])tarjan(i);
	rep(x,1,n)forE(i,x)if(bl[x]!=bl[t[i]])rd[bl[x]]++;
	int mini=n;
	rep(i,1,block)if(rd[i]==0)mini=min(mini,sz[i]);
	rep(i,1,block)if(rd[i]==0&&mini==sz[i]){
		printf("%d\n",mini);
		rep(x,1,n)if(bl[x]==i)printf("%d ",x);
		return 0;
	}
	return 0;
}