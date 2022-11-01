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
const int maxn=1000005;
int n,a[maxn];
i64 f[maxn][3];
const i64 inf=1ll<<60;
int main(){
    // judge();
	read(n);rep(i,1,n)read(a[i]);
	f[0][0]=0;f[0][1]=-inf;f[0][2]=-inf;
	rep(i,1,n){
		f[i][0]=f[i-1][0];f[i][1]=f[i-1][1];f[i][2]=f[i-1][2];
		// f[i][0]=
		f[i][0]=max(f[i][0],f[i-1][1]-a[i]);
		f[i][0]=max(f[i][0],f[i-1][2]+a[i]);
		f[i][1]=max(f[i][1],f[i-1][0]+a[i]);
		f[i][2]=max(f[i][2],f[i-1][0]-a[i]);
	}
	printf("%I64d",f[n][0]);
    return 0;
}