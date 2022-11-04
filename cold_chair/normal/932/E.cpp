#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s =1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

int n, k, s[5005][5005];
ll pi = 1, ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	s[0][0] = 1; fo(i, 1, k) fo(j, 1, i) s[i][j] = (s[i - 1][j - 1] + (ll) s[i - 1][j] * j % mo) % mo;
	fo(i, 1, k) {
		pi = pi * (n - i + 1) % mo;
		ans += s[k][i] * pi % mo * ksm(2, n - i) % mo;
	}
	printf("%I64d", ans % mo);
}