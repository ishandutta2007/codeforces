#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define int long long
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,l,a[100005];
long double c1[100005],c2[100005];
long double getp1(long double t){
	if (t>c1[n+1])return a[n+1];
	int p=1;
	while(c1[p]<t)p++;
	p--;
	return a[p]+(t-c1[p])*(p+1);
}
long double getp2(long double t){
	if (t>c2[0])return a[0];
	int p=n+1;
	while(c2[p]<t)p--;
	p++;
	return a[p]-(t-c2[p])*(n+2-p);
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>l;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		a[0]=0,a[n+1]=l;
		c1[0]=0.0,c2[n+1]=0.0;
		for (int i=1;i<=n+1;i++)c1[i]=c1[i-1]+(a[i]-a[i-1])*1.0/i;
		for (int i=n;i>=0;i--)c2[i]=c2[i+1]+(a[i+1]-a[i])*1.0/(n+1-i);
		long double l=0.0,r=1e9,ans;
		while(r-l>0.0000000001){
			long double mid=(l+r)/2;
			if (getp1(mid)>getp2(mid))ans=mid,r=mid;
			else l=mid;
		}
		printf("%.9Lf\n",ans);
	}
	return 0;
}