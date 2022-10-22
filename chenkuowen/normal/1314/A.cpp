#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
typedef long long ll;
pair<int,int> a[MAX_N];
priority_queue<int> q;
int main(){
	ll sum=0,ans=0;
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i].first);
	for(int i=1;i<=n;++i) scanf("%d",&a[i].second);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		 for(int j=a[i-1].first;j<a[i].first;++j){
			 if(q.empty()) break;
			 sum-=q.top(); q.pop();
	//		 printf("{%d %lld}",i,sum);
			 ans+=sum;
		 }
	     q.push(a[i].second); sum+=a[i].second;
	}
	for(int j=a[n].first;;++j){
		if(q.empty()) break;
		sum-=q.top(); q.pop();
		ans+=sum;
	}
	printf("%lld\n",ans);
	return 0;
}