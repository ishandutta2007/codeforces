#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
const double eps=1e-6;
int n,m,k;
char a[N];
int c[N];
double dp[N];
int cnt[N];
int check(double key){
	int i;
	for(i=1;i<=n;i++) dp[i]=0;
	for(i=1;i<=n;i++){
		if(i-m<0||dp[i-m]+c[i]-c[i-m]+key<dp[i-1]){
			dp[i]=dp[i-1];
			cnt[i]=cnt[i-1];
		}
		else{
			dp[i]=dp[i-m]+c[i]-c[i-m]+key;
			cnt[i]=cnt[i-m]+1;
		}
	}
	return cnt[n];
}
int main(){
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	n+=m;
	scanf("%s",a+1);
	int cl=0,cu=0,ans=n;
	for(i=1;i<=n;i++){
		c[i]=(a[i]>='a'&&a[i]<='z');
		c[i]+=c[i-1];
	}
	cl=c[n];
	if(check(1e7)<k)
		ans=min(ans,cl-int(dp[n]-cnt[n]*1e7+0.5));
	else{
		double l=-1e7,r=1e7;
		while(r-l>eps){
			double mid=(l+r)/2.;
			if(check(mid)<k) l=mid;
			else r=mid;
		}
		check(l);
		ans=min(ans,cl-int(dp[n]-k*l+0.5));		
	}
	for(i=1;i<=n;i++){
		c[i]=(a[i]>='A'&&a[i]<='Z');
		c[i]+=c[i-1];
	}
	cu=c[n];
	if(check(1e7)<k)
		ans=min(ans,cl-int(dp[n]-cnt[n]*1e7+0.5));
	else{
		double l=-1e7,r=1e7;
		while(r-l>eps){
			double mid=(l+r)/2.;
			if(check(mid)<k) l=mid;
			else r=mid;
		}
		check(l);
		ans=min(ans,cu-int(dp[n]-k*l+0.5));		
	}
	cout<<max(ans,0);
	return 0;
}