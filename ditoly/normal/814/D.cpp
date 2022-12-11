#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define MN 1000
struct P{int x,y,r;}p[MN+5];
bool cmp(const P&a,const P&b){return a.r<b.r;}
struct edge{int nx,t;}e[MN+5];
int h[MN+5],en,r[MN+5];
ll f[MN+5][2][2];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
inline ll sqr(ll x){return x*x;}
void dp(int x)
{
	ll s[2][2];s[0][0]=s[0][1]=s[1][0]=s[1][1]=0;
	for(int i=h[x];i;i=e[i].nx)
	{
		dp(e[i].t);
		s[0][0]+=f[e[i].t][0][0];
		s[0][1]+=f[e[i].t][0][1];
		s[1][0]+=f[e[i].t][1][0];
		s[1][1]+=f[e[i].t][1][1];
	}
	f[x][0][0]=max(s[1][0]+sqr(p[x].r),s[0][1]+sqr(p[x].r));
	f[x][0][1]=max(s[1][1]+sqr(p[x].r),s[0][0]-sqr(p[x].r));
	f[x][1][0]=max(s[0][0]-sqr(p[x].r),s[1][1]+sqr(p[x].r));
	f[x][1][1]=max(s[0][1]-sqr(p[x].r),s[1][0]-sqr(p[x].r));
}
int main()
{
	int n=read(),i,j;ll ans=0;
	for(i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),p[i].r=read();
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;++i)for(j=i+1;j<=n;++j)
		if(sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y)<=sqr(p[j].r)){ins(j,i);r[i]=1;break;}
	for(i=1;i<=n;++i)if(!r[i])dp(i),ans+=f[i][0][0];
	printf("%.10lf",acos(-1)*ans);
}