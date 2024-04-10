#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n;
ll a[MAXN], b[MAXN], x;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &a[i], &b[i]), x ^= a[i], b[i] ^= a[i];
	for (int i = 61; ~i; i--){
		pair<ll, int>	mn(ll(8e18), -1);
		for (int j = 0; j < n; j++)
			if ((b[j] >> i) & 1 && 1ll<<(i+1) > b[j])
				mn = min(mn, {b[j], j});
		if (mn.S == -1)	continue;
		for (int j = 0; j < n; j++)
			if (j ^ mn.S && (b[j] >> i) & 1)
				b[j] ^= mn.F;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (!b[i])	cnt++;
	ll y = 0;
	for (int i = 0; i < n; i++){
		if (!b[i])	continue;

		ll temp = b[i];
		int j = 0;
		while (b[i]){
			b[i] >>= 1;
			j++;
		}
		j--;
		if ((x>>j)&1)
			y ^= temp;
	}
	cnt = n - cnt;
	if (x ^ y)
		printf("1/1\n");
	else
		printf("%lld/%lld\n", (1ll<<cnt)-1, 1ll<<cnt);
	return 0;
}