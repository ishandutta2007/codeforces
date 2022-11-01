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
const int maxn=100005;
int head[maxn],t[maxn<<1],ne[maxn<<1],num,n,m,col[maxn];
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}bool chk=0;
inline void dfs(int x){
	forE(i,x)if(col[t[i]]==-1){
		col[t[i]]=col[x]^1,dfs(t[i]);
	}else{
		if((col[t[i]]^col[x])!=1)chk=1;
	}
}
int main(){
	read(n);read(m);
	rep(i,1,n)head[i]=-1,col[i]=-1;
	rep(i,1,m){
		int x,y;read(x);read(y);addedge(x,y);
	}
	rep(i,1,n)if(col[i]==-1)col[i]=0,dfs(i);
	if(chk){
		puts("-1");return 0;
	}
	int num1=0,num2=0;
	rep(i,1,n)if(col[i]==0)num1++;else num2++;
	printf("%d\n",num1);
	rep(i,1,n)if(col[i]==0)printf("%d ",i);puts("");
	printf("%d\n",num2);
	rep(i,1,n)if(col[i]==1)printf("%d ",i);puts("");
	return 0;
}