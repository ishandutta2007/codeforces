#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int a,t;
}a[1000005];
bool cmp(node a,node b){
	if (a.t==b.t)return a.a<b.a;
	return a.t<b.t;
}
int t,n,s,aa,bb,sum[1000005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>s>>aa>>bb;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%I64d",&x);
			if (x==0)a[i].a=aa;
			else a[i].a=bb;
		}
		for (int i=1;i<=n;i++){
			scanf("%I64d",&a[i].t);
		}
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].a;
		int ans=0,numa=0,numb=0;
		if (sum[n]<=s)ans=n;
		for (int i=n;i>=1;i--){
			if (a[i].a==aa)numa++;
			else numb++;
			if (sum[i-1]>=a[i].t)continue;
			int rest=a[i].t-sum[i-1]-1;
			int tmp=i-1;
			if (rest>=numa*aa)tmp+=numa+min(numb,(rest-numa*aa)/bb);
			else tmp+=min(rest/aa,numa);
			ans=max(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}