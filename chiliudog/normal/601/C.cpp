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
const int maxn=105;
typedef double ld;
ld f[maxn][maxn*maxn*10],sum[maxn][maxn*maxn*10];
int a[maxn],n,m;
int main(){
//	judge();
	read(n);read(m);
	if(m==1){
		puts("1");
		return 0;
	}
	int tot=0;
	rep(i,1,n)read(a[i]),tot+=a[i];
	f[0][0]=1;
	rep(i,1,n){
		sum[i-1][0]=f[i-1][0];
		rep(j,1,i*m)sum[i-1][j]=(sum[i-1][j-1]+f[i-1][j]);
		rep(j,1,i*m){
			int r=j-1,l=j-m;
			f[i][j]=sum[i-1][r];if(l>0)f[i][j]-=sum[i-1][l-1];f[i][j]/=(m-1);
			if(j>=a[i])f[i][j]-=f[i-1][j-a[i]]/(m-1);
		}
	}ld pos=0;
	rep(j,0,tot-1)pos+=f[n][j];
	printf("%.10f\n",pos*(m-1)+1);
	return 0;
}