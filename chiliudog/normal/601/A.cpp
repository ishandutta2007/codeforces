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
const int maxn=405;
int n,m;
int d[maxn][maxn];
bool e[maxn][maxn];
const int inf=1<<29;
int main(){
	read(n);read(m);
	rep(i,1,m){
		int x,y;read(x);read(y);
		e[x][y]=1;e[y][x]=1;
	}
	if(e[1][n]){
		rep(i,1,n)rep(j,1,n)e[i][j]=!e[i][j];
	}
	rep(i,1,n)rep(j,1,n){
		if(i==j)continue;
		if(e[i][j])d[i][j]=1;else d[i][j]=inf;
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
	if(d[1][n]==inf){
		puts("-1");
	}else{
		printf("%d\n",d[1][n]);
	}
	return 0;
}