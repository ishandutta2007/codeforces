#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int t,b;
}a[300005];
bool cmp(node a,node b){
	return a.b<b.b;
}
int n,k,nowlen,ans;
priority_queue <int>h;
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&a[i].t,&a[i].b);
	sort(a+1,a+1+n,cmp);
	for (int i=n;i>=1;i--){
		if (h.size()==k)nowlen+=h.top(),h.pop();
		ans=max(ans,a[i].b*(nowlen+a[i].t));
		nowlen+=a[i].t;
		h.push(-a[i].t);
	}
	cout<<ans<<endl;
	return 0;
}