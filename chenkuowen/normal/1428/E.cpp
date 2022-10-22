#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
ll split(int n,int t){
	int y=n/t;
	return 1ll*(n%t)*(y+1)*(y+1)+1ll*(t-n%t)*y*y;
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int c[N],a[N];
int main(){
	ll ans=0;
	int n,k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		c[i]=1; ans+=split(a[i],1);
		q.push(make_pair(split(a[i],2)-split(a[i],1),i));
	}
	for(int i=1;i<=k-n;++i){
//		printf("[%lld %d]",q.top().first,q.top().second);
		ans+=q.top().first;
		int x=q.top().second; q.pop();
		c[x]++;
		if(c[x]+1<=a[x])
			q.push(make_pair(split(a[x],c[x]+1)-split(a[x],c[x]),x));
	}
	printf("%lld\n",ans);
	return 0;
}