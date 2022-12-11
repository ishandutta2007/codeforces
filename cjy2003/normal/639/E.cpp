#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct task
{
	long long miT,mxT;
	int p,t;
	friend bool operator < (task a,task b){return 1ll*a.t*b.p==1ll*b.t*a.p?a.p<b.p:1ll*a.t*b.p<1ll*b.t*a.p;}
}a[150050];
bool cmp(task a,task b){return a.p<b.p;}
int n;
long long tot;
double ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].p);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].t);
	sort(a+1,a+1+n);
	int r;
	long long mi,mx;
	for(int i=1;i<=n;++i)
	{
		r=i;mi=mx=a[i-1].mxT;mx+=a[i].t;
		while(r<n&&1ll*a[i].p*a[r+1].t==1ll*a[i].t*a[r+1].p)++r,mx+=a[r].t;
		for(int j=i;j<=r;++j)a[j].mxT=mx,a[j].miT=mi+a[j].t;
		i=r;
	}
	tot=a[n].mxT;
	sort(a+1,a+1+n,cmp);
	ans=1.0/tot;
	double mi1,mx1;
	for(int i=1;i<=n;++i)
	{
		r=i-1;mx1=0;
		while(a[i].p==a[r+1].p)++r,mx1=max(mx1,1.0*a[r].p*a[r].mxT);
		if(i>1&&mx1>mi1)ans=min(ans,1.0*(a[i].p-a[i-1].p)/(mx1-mi1));
		mi1=1.0*a[i].p*a[i].miT;
		for(int j=i+1;j<=r;++j)mi1=min(mi1,1.0*a[j].p*a[j].miT);
		i=r;
	}
	printf("%.12lf",ans*tot);
	return 0;
}