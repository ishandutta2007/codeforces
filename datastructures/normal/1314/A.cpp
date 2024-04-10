#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int id,val;
}a[500005];
bool cmp(node a,node b){
	return a.id<b.id;
}
int n;
priority_queue<int> h;
int sum,ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i].id);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i].val);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		if (i>1&&a[i].id>a[i-1].id){
			for (int j=1;j<=a[i].id-a[i-1].id;j++){
				if (h.empty())break;
				sum-=h.top();
				h.pop();
				ans+=sum;
			}
		}
		sum+=a[i].val,h.push(a[i].val);
	}
	while(!h.empty()){
		sum-=h.top();
		h.pop();
		ans+=sum;
	}
	cout<<ans<<endl;
	return 0;
}