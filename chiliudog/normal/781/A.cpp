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
int num,head[maxn],t[maxn<<1],ne[maxn<<1],du[maxn];
int col[maxn],n;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline void dfs(int x,int f){
	int nowcol=1;
	forE(i,x)if(t[i]!=f){
		while(nowcol==col[f]||nowcol==col[x])nowcol++;
		col[t[i]]=nowcol++;
	}
	forE(i,x)if(t[i]!=f)dfs(t[i],x);
}
int main(){
    read(n);
    rep(i,1,n)head[i]=-1;
    rep(i,1,n-1){
    	int x,y;read(x);read(y);
    	du[x]++;du[y]++;addedge(x,y);
    }col[1]=1;dfs(1,0);
    int k=0;
    rep(i,1,n)k=max(k,du[i]);
    printf("%d\n",k+1);
    rep(i,1,n)printf("%d ",col[i]);
    return 0;
}