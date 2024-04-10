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
const int maxn=505;
bool f[maxn][maxn][maxn];
int a[maxn],n,k;
int main(){
	//judge();
	read(n);read(k);
	rep(i,1,n)read(a[i]);
	f[0][0][0]=1;
	rep(i,0,n-1)rep(j,0,k)rep(p,j,k)if(f[i][j][p]){
		f[i+1][j][p]=1;
		if(p+a[i+1]<=k)f[i+1][j+a[i+1]][p+a[i+1]]=1,
		f[i+1][j][p+a[i+1]]=1;
	}int res=0;
	rep(j,0,k)if(f[n][j][k])res++;
	printf("%d\n",res);
	rep(j,0,k)if(f[n][j][k])printf("%d ",j);
	return 0;
}