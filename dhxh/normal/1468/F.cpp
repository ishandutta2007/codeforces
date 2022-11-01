#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<numeric>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define frist first
#define bulid build
typedef long long ll;
using namespace std;
int n;
map<pair<ll,ll>,int>q;
pair<ll,ll> cla(pair<ll,ll> a) {
	assert(a.first != 0 || a.second != 0);
	int c = __gcd(abs(a.first),abs(a.second));
	a.first /= c;
	a.second /= c;
	return a;
}
void work() {
	scanf("%d",&n);
	q.clear();
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		auto x = cla(make_pair(c - a,d - b));
		auto tp = make_pair(-x.first,-x.second);
		if(q.find(tp) != q.end()) {
			ans += q[tp];
		}
		q[x]++;
	}
	printf("%lld\n",ans);
	return;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		work();
	}
	return 0;
}
/*
1
4
0 0 1 0
0 0 -1 0
0 0 2 0
0 0 -2 0

2
2
0 0 3 -4
0 0 -6 8
2
0 0 3 -4
0 0 -6 8
*/