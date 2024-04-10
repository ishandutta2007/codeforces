#include <bits/stdc++.h>
#define ll long long
#define mp std::make_pair
#define maxn 1000005
int n,k,a[maxn],d[maxn];
ll sum;
std::priority_queue<std::pair<ll,int> >q;
ll sqr(ll x) { return x*x; }
ll opt(ll x,ll d) {
	d = std::min(d,x);
	ll small = x / d;
	ll big = small + 1;
	ll cntsmall = d - x % d;
	ll cntbig = x % d;
	return sqr(small) * cntsmall + sqr(big) * cntbig ;
} ll delta(ll x,ll d) {
	return opt(x,d) - opt(x,d+1);
}
int main() {
	scanf("%d%d",&n,&k);
	int cnt = k - n;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		sum += (ll) a[i] * a[i];
		d[i] = 1;
		q.push(mp(delta(a[i],d[i]),i));
	} while (cnt) {
		auto P = q.top(); q.pop();
	//	printf("do %d -= %lld\n",P.second,P.first);
		sum -= P.first;
		int x = P.second;
		d[x] ++;
		q.push(mp(delta(a[x],d[x]),x));
		cnt --;
	} printf("%lld",sum);
	
	return 0;
}