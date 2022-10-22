#include<bits/stdc++.h>
typedef double lf;
const lf INF=1e18,PI=acos(-1);
const int N=53,D=1<<15,K=15,Q=100000;
int n,m,t,rev[D];lf x,dp[N][D];
struct edge{
	int v;lf c,t,p[D],s[D];
	edge(){v=0;c=t=0;for(int i=0;i<D;i++)p[i]=s[i]=0;}
};
std::vector<edge>g[N];
struct complx{
	lf x,y;
	inline complx operator*(const complx&b){return(complx){x*b.x-y*b.y,x*b.y+y*b.x};}
	inline complx operator+(const complx&b){return(complx){x+b.x,y+b.y};}
	inline complx operator-(const complx&b){return(complx){x-b.x,y-b.y};}
	inline complx operator/(const lf&b){return(complx){x/b,y/b};}
}t0[D],t1[D];
inline void Init(int K){
	for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)<<K-1;
}
inline void Fft(complx*a,int f,int K){
	complx tmp0,tmp1,w,s;
	for(int i=0;i<(1<<K);i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int k=1;k<(1<<K);k<<=1){
	  w=(complx){cos(PI/k),f*sin(PI/k)};
	  for(int i=0;i<(1<<K);i+=k+k){
		s=(complx){1,0};
		for(int j=0;j<k;j++,s=s*w){
		  tmp0=a[i+j],tmp1=a[i+k+j]*s;
		  a[i+j]=tmp0+tmp1,a[i+k+j]=tmp0-tmp1;
		}
	  }
	}
	if(f<0)for(int i=0;i<(1<<K);i++)a[i]=a[i]/(1<<K);
}
void Solve(int l,int r){
	int u,m=l+r>>1,K;
	if(l==r){
	  if(l)for(u=1;u<=n;u++)
		for(int i=0;i<g[u].size();i++){
		  g[u][i].t-=g[u][i].p[l];
		  dp[u][l]=std::min(dp[u][l],g[u][i].c+g[u][i].s[l]+dp[g[u][i].v][0]*g[u][i].t);
		}
	  return;
	}
	Solve(l,m);
	for(K=1;(1<<K)<=r-l+1;++K);
	Init(K);
	for(u=1;u<=n;u++)
	  for(int i=0;i<g[u].size();i++){
		for(int j=0;j<(1<<K);j++)t0[j]=t1[j]=(complx){0,0};
		for(int j=l;j<=m;j++)t0[j-l]=(complx){dp[g[u][i].v][j],0};
		for(int j=1;j<=r-l+1;j++)t1[j]=(complx){g[u][i].p[j],0};
		Fft(t0,1,K),Fft(t1,1,K);
		for(int j=0;j<(1<<K);j++)t0[j]=t0[j]*t1[j];
		Fft(t0,-1,K);
		for(int j=m+1;j<=r;j++)g[u][i].s[j]+=t0[j-l].x;
	  }
	Solve(m+1,r);
}
int main(){
	edge e;int u;
	scanf("%d%d%d%lf",&n,&m,&t,&x),++t;
	for(;m--;){
	  scanf("%d%d%lf",&u,&e.v,&e.c);
	  for(int j=1;j<t;j++)scanf("%lf",&e.p[j]),e.p[j]/=Q;
	  e.t=1;
	  g[u].push_back(e);
	}
	for(u=1;u<n;u++)
	  for(int j=0;j<=t;j++)dp[u][j]=INF;
	for(int j=0;j<=t;j++)dp[n][j]=j?0:x;
	for(int j=1;j<=n;j++)
	  for(u=1;u<=n;u++)for(int i=0;i<g[u].size();i++)
		dp[u][0]=std::min(dp[u][0],dp[g[u][i].v][0]+g[u][i].c);
	Solve(0,t);
	printf("%.12lf\n",dp[1][t]);
	return 0;
}