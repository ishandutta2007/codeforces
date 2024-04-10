#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<set>

using namespace std;

typedef long long ll;

const ll max_n = 1e3 + 100;
const ll max_k = 1e6 + 100;

ll n, m, k;
ll p;
ll a[max_n][max_n];
multiset<ll>	sumr, sumc;
ll aa, bb, ans = -1e15;
ll pr[max_k], pc[max_k];

int main(){
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &p);
	for (ll i = 0; i < n; i++){
		ll s = 0;
		for (ll j = 0; j < m; j++){
			scanf("%I64d", &a[i][j]);
			s += a[i][j];
		}
		sumr.insert(s);
	}
	for (ll i = 1; i <= k; i++){
		set<ll>::iterator it = sumr.end();
		it--;
		pr[i] = pr[i - 1] + *it;

		ll z = *it;
		sumr.erase(it);
		sumr.insert(z - m * p);
	}

	for (ll j = 0; j < m; j++){
		ll s = 0;
		for (ll i = 0; i < n; i++)		
			s += a[i][j];
		sumc.insert(s);
	}	

	for (ll i = 1; i <= k; i++){
		set<ll>::iterator it = sumc.end();
		it--;
		pc[i] = pc[i - 1] + *it;

		ll z = *it;
		sumc.erase(it);
		sumc.insert(z - n * p);
	}

	for (ll i = 0; i <= k; i++)
		ans = max(ans, pr[i] + pc[k-i] - p * i * (k - i));
	printf("%I64d\n", ans);
	return 0;
}