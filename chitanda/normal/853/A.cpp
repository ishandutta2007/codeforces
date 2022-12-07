#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, k;
int c[300100];
int ans[300100];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", c + i);
	}
	ll res = 0;
	priority_queue<pair<int, int> > q;
	ll now = 0;
	for(int i = 1; i <= k; ++i){
		res += (ll)c[i] * (k - i);
		q.push(mkp(c[i], i));
		now += c[i];
	}
	for(int i = k + 1; i <= n + k; ++i){
		res += now;
		if(i <= n){
			now += c[i];
			q.push(mkp(c[i], i));
		}		
		auto t = q.top();
		q.pop();
		now -= t.fi;
		ans[t.se] = i;
	}
	
	printf("%lld\n", res);
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}