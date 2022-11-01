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
const int maxn=3005;
int num,head[maxn],t[maxn<<1],ne[maxn<<1];
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
int s[maxn],tt[maxn],v[maxn];
int x[maxn],sum,n;
bool vis[maxn];
inline pin operator + (const pin &a,const pin &b){
	return mk(a.w1+b.w1,a.w2+b.w2);
}
inline pin dfs(int xx,int fa){
	pin res=mk(x[xx],1);vis[xx]=1;
	forE(i,xx)if(t[i]!=fa)
		res=res+dfs(t[i],xx);
	return res;
}
int main(){
	read(n);
	rep(i,1,n-1){
		read(s[i]),read(tt[i]),read(v[i]);
	}
	rep(i,1,n)read(x[i]),sum+=x[i];int ans=0;
	rep(x,1,n-1){
		rep(i,1,n)head[i]=-1;num=0;
		rep(i,1,n-1)if(v[i]<v[x])addedge(s[i],tt[i]);
		memset(vis,0,sizeof(vis));bool flag=1;
		rep(i,1,n)if(!vis[i]){
			pin w=dfs(i,-1);
			if(sum-w.w1<w.w2)flag=0;
		}if(flag)ans=max(ans,v[x]);
	}cout<<ans<<endl;
	return 0;
}