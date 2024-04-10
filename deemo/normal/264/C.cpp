#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

int n, q, c[MAXN];
ll val[MAXN], d[MAXN], x, y;
pair<ll, ll>	mx[2];

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)	scanf("%lld", &val[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]), c[i]--;
	while (q--){
		scanf("%lld %lld", &x, &y);

		fill(d, d + MAXN, -INF);
		mx[0] = mx[1] = {-INF, 0};
		ll ans = 0;

		for (int i = 0; i < n; i++){
			ll temp = d[c[i]] + x * val[i];
			temp = max(temp, y * val[i]);
			for (int w = 0; w < 2; w++)
				if (mx[w].S ^ c[i])
					temp = max(temp, mx[w].F + y * val[i]);

			d[c[i]] = max(d[c[i]], temp);
			ans = max(ans, temp);
			bool fl = 0;
			for (int w = 0; w < 2; w++)
				if (mx[w].S == c[i])
					mx[w].F = d[c[i]], fl = 1;
	
			if (!fl)
				mx[1] = max(mx[1], {d[c[i]], c[i]});
			if (mx[0] < mx[1])
				swap(mx[0], mx[1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}