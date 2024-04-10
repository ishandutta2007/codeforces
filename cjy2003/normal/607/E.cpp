#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
double x,y,a[50050],b[50050],ans;
struct data
{
	double angle;
	int id;
	friend bool operator < (data a,data b){return a.angle<b.angle;}
}d[100010];
int cnt,last[50050];
int sum[100010];
inline void add(int p,int w){while(p<=cnt)sum[p]+=w,p+=p&-p;}
inline int qry(int p){int s=0;while(p)s+=sum[p],p-=p&-p;return s;}
int check(double r)
{
	double A,B,C,nx,ny,delt;
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		A=1+a[i]*a[i];
		B=-2*x+2*a[i]*(b[i]-y);
		C=x*x+(b[i]-y)*(b[i]-y)-r*r;
		if(B*B<=4*A*C)continue;
		delt=sqrt(B*B-4*A*C);
		nx=(-B+delt)/A/2;ny=a[i]*nx+b[i];
		d[++cnt]=data{atan2(ny-y,nx-x),i};
		nx=(-B-delt)/A/2;ny=a[i]*nx+b[i];
		d[++cnt]=data{atan2(ny-y,nx-x),i};
	}
	sort(d+1,d+1+cnt);
	int res=0;
	for(int i=1;i<=cnt;++i)
	{
		if(last[d[i].id])res+=qry(i)-qry(last[d[i].id]),add(last[d[i].id],-1),last[d[i].id]=0;
		else add(i,1),last[d[i].id]=i;
	}
	return res;
}
int pre[100010],nxt[100010],lst;
inline double calc(int i,int j)
{
//	printf("%d %d\n",i,j);
	double nx=(b[j]-b[i])/(a[i]-a[j]),ny=nx*a[i]+b[i];
//	printf("%lf %lf\n",nx,ny);
	return sqrt((nx-x)*(nx-x)+(ny-y)*(ny-y));
}
int main()
{
	scanf("%d %lf %lf %d",&n,&x,&y,&m);x/=1000,y/=1000;
	for(int i=1;i<=n;++i)scanf("%lf %lf",&a[i],&b[i]),a[i]/=1000,b[i]/=1000;
	double l=0,r=100000000000000,mid;
	for(int t=1;t<=100;++t)
	{
		mid=(l+r)/2;
		if(check(mid)>=m)r=mid;
		else l=mid;
	}
//	printf("%lf\n",l);
	check(l);
//	for(int i=1;i<=cnt;++i)printf("%lf %d\n",d[i].angle,d[i].id);
	int res=0;lst=0;
	for(int i=1;i<=cnt;++i)
	{
		if(last[d[i].id])
		{
			int p=lst;
			while(p>last[d[i].id])++res,ans+=calc(d[i].id,d[p].id),p=pre[p];
			nxt[pre[p]]=nxt[p];pre[nxt[p]]=pre[p];if(p==lst)lst=pre[lst];
		}
		else
		{
			nxt[lst]=i;pre[i]=lst;lst=i;
			last[d[i].id]=i;
		}
	}
	ans+=(m-res)*l;
	printf("%.12lf",ans);
	return 0;
}