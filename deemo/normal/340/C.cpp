#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

ll n;
ll a[max_n];
ll p[max_n];
ll sum, tsum;

int main(){
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
		tsum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + a[i];
	
	for (ll i = 1; i < n; i++){
		sum += i * a[i];
		sum -= p[i];
	}
	sum *= 2;
	sum += tsum;

	ll t = __gcd(sum, ll(n));
	sum /= t;
	n /= t;
	printf("%I64d %I64d\n", sum, n);
	return 0;
}