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
const int maxn=1e2+5;
int num,head[maxn],t[maxn*maxn<<1],ne[maxn*maxn<<1],v[maxn*maxn<<1];
int n,m;
int f[maxn][maxn][27];
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;v[num]=z;
}
inline int dfs(int x,int y,int z){
	int &res=f[x][y][z];
	if(res!=-1)return res;
	res=1;
	forE(i,x){
		if(v[i]>=z){
			res&=dfs(y,t[i],v[i]);
		}
	}res=!res;
	return res;
}
int main(){
	memset(f,-1,sizeof f);
	read(n);read(m);
	rep(i,1,n)head[i]=-1;
	rep(i,1,m){
		int x,y;char z[5];
		read(x);read(y);
		scanf("%s",z);
		addedge(x,y,z[0]-'a'+1);
	}
	rep(i,1,n){
		rep(j,1,n)if(dfs(i,j,0))putchar('A');
		else putchar('B');
		puts("");
	}
	return 0;
}