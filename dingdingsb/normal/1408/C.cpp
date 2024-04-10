#include<bits/stdc++.h>
using namespace std;
int t,n,L,a[100000+100];
int av[100000+100],bv[100000+100]; 
double at[100000+100],bt[100000+100];
const double eps=1e-7;
bool check(double time){
	int l1=0,r1=n+1,res;
	while(l1<=r1){
		int mid=l1+r1>>1;
		if(at[mid]<time)res=mid,l1=mid+1;
		else r1=mid-1;
	}
	double ax=a[res]+(time-at[res])*av[res];
	int l2=0,r2=n+1;
	while(l2<=r2){
		int mid=l2+r2>>1;
		if(bt[mid]<time)res=mid,r2=mid-1;
		else l2=mid+1;
	}
	double bx=a[res]-(time-bt[res])*bv[res];
	return bx<=ax;	
} 
signed main(){
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&L);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0,a[n+1]=L;
		at[0]=0,av[0]=1;
		for(int v=1,i=1;i<=n+1;i++)
			at[i]=at[i-1]+1.0*(a[i]-a[i-1])/v,
			v++,av[i]=v;
		bt[n+1]=0;bv[n+1]=1;
		for(int v=1,i=n;i>=0;i--)
			bt[i]=bt[i+1]+1.0*(a[i+1]-a[i])/v,
			v++,bv[i]=v;
		double l=0,r=1.0*L/2,ans;
		while(l+eps<r){
			double mid=(l+r)/2;
			if(check(mid))ans=mid,r=mid;
			else l=mid;
		}
		printf("%.10lf\n",ans);
	}
	
	return 0;
}