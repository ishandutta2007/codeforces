#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 10;

ll n, k;
ll vec[MAXN], sm, p[MAXN];

bool ok(ll mid){
	if (n * mid < sm)	return false;
	ll pos = upper_bound(vec, vec + n, mid) - vec;
	return (p[n] - p[pos]) - (n - pos) * mid <= k;
}

bool ok2(ll mid){
	if (n * mid > sm)	return false;
	ll pos = upper_bound(vec, vec + n, mid) - vec;
	ll z = pos * mid - p[pos];
	return z <= k;
}

int main(){
	scanf("%I64d %I64d", &n, &k);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &vec[i]), sm += vec[i];
	sort(vec, vec +	 n);
	for (ll i = 0; i < n; i++)
		p[i + 1] = p[i] + vec[i];
	
	ll b = 0, e = 1e9, mx = 1e9;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (ok(mid))
			mx = mid, e = mid - 1;
		else
			b = mid + 1;
	}

	b = 0, e = 1e9; ll mn = 0;
	while (b <= e){
		ll mid = (b + e) / 2;
		if (ok2(mid))
			mn = mid, b = mid + 1;
		else
			e = mid - 1;
	}

	printf("%I64d\n", mx - mn);
	return 0;
}