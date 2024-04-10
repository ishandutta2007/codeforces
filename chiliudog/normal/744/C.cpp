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
const int maxn=17;
int f[1<<maxn][maxn*maxn],lg2[1<<maxn];
int r[maxn*maxn],b[maxn*maxn],tp[maxn*maxn],n;
pin sta[1<<maxn];const int inf=2e9;
inline void upd(int &x,int y){
	x=max(x,y);
}
int main(){
    // judge();
	read(n);
	rep(i,0,(1<<n)-1)rep(j,0,n*n)f[i][j]=-inf;int sumx=0,sumy=0;
	rep(i,1,n){
		char ch=getchar();
		while(ch!='R'&&ch!='B')ch=getchar();
		read(r[i]);read(b[i]);sumx+=r[i];sumy+=b[i];
		tp[i]=ch=='R';
	}rep(i,1,n)lg2[1<<(i-1)]=i;
	rep(i,1,(1<<n)-1){
		sta[i]=sta[i-lowbit(i)];
		if(tp[lg2[lowbit(i)]])
			sta[i].w1++;
		else
			sta[i].w2++;
	}f[0][0]=0;
	rep(i,0,(1<<n)-1)rep(j,0,n*n)if(f[i][j]!=-inf){
		rep(k,0,n-1)if(!((1<<k)&i)){
			upd(f[(1<<k)|i][j+min(r[k+1],sta[i].w1)],f[i][j]+min(b[k+1],sta[i].w2));
		}
	}int ans=inf;
	rep(j,0,n*n)if(f[(1<<n)-1][j]!=-inf){
		ans=min(ans,max(sumx-j,sumy-f[(1<<n)-1][j]));
	}cout<<ans+n;
    return 0;
}