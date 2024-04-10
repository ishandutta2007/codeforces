#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue <ll> PQ;
ll n,k,ans;
ll A[1010];

int main()
{
	ll i,a;
	
	scanf("%lld%lld%lld",&n,&k,&a); k += a;
	
	for(i=0;i<n;i++) scanf("%lld",A+i);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		if(a < A[i]) PQ.push(A[i]-a);
		else PQ.push(a-A[i]);
	}
	
	for(;k--;){
		a = PQ.top(); PQ.pop();
		if(a == 0) PQ.push(a+1);
		else PQ.push(a-1);
	}
	
	for(;PQ.size();PQ.pop()) ans += PQ.top() * PQ.top();
	
	printf("%lld\n",ans);
	
	return 0;
}