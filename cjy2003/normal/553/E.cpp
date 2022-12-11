#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const double eps=1e-7,pi=3.141592653589793;
vector<pair<int,int> >E[51];
vector<int>E1[51];
int n,m,t,cost,a[110],b[110],c[110],p[110][20020],suf[110][20020],dis[51],lim=65536;
bool vis[51];
priority_queue<pair<int,int> >q;
double dp[51][20020],tmp[20020],S[101][20020];
struct complex
{
	double x,y;
	friend complex operator + (complex a,complex b){return complex{a.x+b.x,a.y+b.y};}
	friend complex operator - (complex a,complex b){return complex{a.x-b.x,a.y-b.y};}
	friend complex operator * (complex a,complex b){return complex{a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y};}
}w[16][32768];
void init()
{
	for(int len=1,i=0;len<65536;len<<=1,++i)
		for(int j=0;j<len;++j)w[i][j]=complex{cos(j*pi/len),sin(j*pi/len)};
}
void fft(complex f[],int opt,int lim)
{
	static int r[65536],now;
	if(now!=lim)
	{
		now=lim;
		for(int i=1;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);
	}
	for(int i=1;i<lim;++i)if(i<r[i])swap(f[i],f[r[i]]);
	complex x,y;
	for(int len=1,i=0;len<lim;len<<=1,++i)
		for(int j=0;j<lim;j+=len<<1)
			for(int k=0;k<len;++k)
			{
				x=f[j+k],y=f[j+k+len]*w[i][k];
				f[j+k]=x+y;
				f[j+k+len]=x-y;
			}
	if(opt==-1)
	{
		reverse(f+1,f+lim);
		for(int i=0;i<lim;++i)f[i].x/=lim;
	}
}
void mul(double A[],double B[],double C[],int lena,int lenb)
{
	static complex X[65536],Y[65536];
	int lim=1;
	while(lim<lena+lenb-1)lim<<=1;
	for(int i=0;i<lena;++i)X[i]=complex{A[i],0};
	for(int i=lena;i<lim;++i)X[i]=complex{0,0};
	for(int i=0;i<lenb;++i)Y[i]=complex{B[i],0};
	for(int i=lenb;i<lim;++i)Y[i]=complex{0,0};
	fft(X,1,lim),fft(Y,1,lim);
	for(int i=0;i<lim;++i)X[i]=X[i]*Y[i];
	fft(X,-1,lim);
	for(int i=0;i<lena+lenb-1;++i)C[i]=X[i].x;
}
double A[30030],B[30030],C[30030];
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<n;++i)
		{
			dp[i][l]=1e10;
			for(auto u:E1[i])dp[i][l]=min(dp[i][l],S[u][l]+c[u]);
		}
		return ;
	}
	int mid=l+r>>1;
	solve(mid+1,r);
	for(int i=1;i<=m;++i)
	{
		for(int j=mid+1;j<=r;++j)A[j-mid-1]=dp[b[i]][j];
		for(int j=1;j<=r-l;++j)B[j-1]=p[i][j]/100000.0;
		reverse(B,B+r-l);
		mul(A,B,C,r-mid,r-l);
		for(int j=l,k=r-mid-1;j<=mid;++j,++k)S[i][j]+=C[k];
	}
	solve(l,mid);
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&t,&cost);
	init();
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		E1[a[i]].push_back(i);
		E[b[i]].push_back(make_pair(a[i],c[i]));
		for(int j=1;j<=t;++j)scanf("%d",&p[i][j]);
		for(int j=t;j;--j)suf[i][j]=suf[i][j+1]+p[i][j];
	}
	memset(dis+1,0x3f,n<<2);
	int x,y;
	dis[n]=cost,q.push(make_pair(-cost,n));
	while(!q.empty())
	{
		x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto b:E[x])
			if(dis[x]+b.second<dis[y=b.first])
			{
				dis[y]=dis[x]+b.second;
				q.push(make_pair(-dis[y],y));
			}
	}
//	printf("!!!\n");
	for(int i=1;i<=m;++i)
		for(int j=0;j<=t;++j)
			S[i][j]+=dis[b[i]]*(suf[i][t+1-j]/100000.0);
//	printf("!!!\n");
	solve(0,t);
/*	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=t;++j)printf("%lf ",dp[i][j]);
		printf("\n");
	}*/
	printf("%.12lf",dp[1][0]);
	return 0;
}