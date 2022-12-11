#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans,n; ll x,k,a[211111];
priority_queue<ll,vector<ll>,greater<ll> >q;
int main(){
	scanf("%d%lld%lld",&n,&k,&x);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n); ans=n;
	for(int i=1;i<n;++i)q.push(a[i+1]-a[i]);
	while(!q.empty()&&q.top()/x+(q.top()%x?1:0)<=k+1)
		k-=max(0ll,q.top()/x+(q.top()%x?1:0)-1),ans--,q.pop();
	printf("%d",ans);
}