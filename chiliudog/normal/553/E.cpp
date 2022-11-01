#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}x*=f;
}
inline void judge(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
typedef double ld;
ld f[105][20005],g[105][20005],p[105][20005],s[105][20005];
int n,m,T,x;int st[105],ed[105],cost[105];
namespace fft{
	const int maxn=100005;
	struct sim{
		double r,i;
		inline sim(){}
		inline sim(ld _r,ld _i){r=_r;i=_i;}
	}a[maxn],b[maxn];
	inline sim operator + (const sim &a,const sim &b){
		return sim(a.r+b.r,a.i+b.i);
	}
	inline sim operator - (const sim &a,const sim &b){
		return sim(a.r-b.r,a.i-b.i);
	}	
	inline sim operator * (const sim &a,const sim &b){
		return sim(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
	}int rev[maxn],len,lim;
	inline void init(int n,int m){
		len=1;lim=0;
		while(len<=n+m)len<<=1,lim++;
		rep(i,0,len-1)rev[i]=((rev[i>>1])>>1)|((i&1)<<(lim-1));
	}const ld pi=acos(-1.0);
	inline void FFT(sim a[],int on){
		rep(i,0,len-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int h=2;h<=len;h<<=1){
			sim wn=sim(cos(2*pi*on/h),sin(2*pi*on/h));
			for(int j=0;j<len;j+=h){
				sim w=sim(1,0);
				rep(k,0,h/2-1){
					sim u=a[j+k],t=a[j+k+h/2]*w;
					a[j+k]=u+t;a[j+k+h/2]=u-t;w=w*wn;
				}
			}
		}if(on==-1)rep(i,0,len-1)a[i].r/=len;
	}
	inline void trans(int x,int l,int r){
		int md=(r+l)/2;
		int t=r-l-1+r-md;
		init(0,t);
		rep(i,0,len-1)a[i]=sim(0,0),b[i]=sim(0,0);
		rep(i,md+1,r)a[i-md-1].r+=f[ed[x]][i];
		rep(i,1,r-l)b[r-l-i].r+=p[x][i];
		FFT(a,1);FFT(b,1);
		rep(i,0,len-1)a[i]=a[i]*b[i];
		FFT(a,-1);
		rep(i,l,md)g[x][i]+=a[i+r-l-md-1].r;
	}
}
inline void solve(int l,int r){
	if(l==r){
		rep(i,1,m)
			f[st[i]][l]=min(f[st[i]][l],g[i][l]+cost[i]);
		return;
	}int md=(l+r)>>1;
	solve(md+1,r);
	rep(i,1,m)fft::trans(i,l,r);
	solve(l,md);
}
const int inf=1e9;
int dist[105];
int main(){
	read(n);read(m);read(T);read(x);
	rep(i,1,m){
		read(st[i]);read(ed[i]);read(cost[i]);		
		rep(j,1,T)scanf("%lf",&p[i][j]),p[i][j]/=100000.0;
		per(j,T,1)s[i][j]=p[i][j]+s[i][j+1];
	}
	rep(i,1,n)dist[i]=inf;
	dist[n]=0;
	rep(i,1,n)rep(j,1,m)dist[st[j]]=min(dist[st[j]],dist[ed[j]]+cost[j]);
	rep(i,1,n-1)rep(j,0,T)f[i][j]=inf;
	rep(i,1,n)f[i][T+1]=dist[i]+x;			
	rep(i,1,m)rep(j,0,T)
		g[i][j]=s[i][T+1-j]*f[ed[i]][T+1];
	solve(0,T);
	printf("%.10f\n",f[1][0]);
}