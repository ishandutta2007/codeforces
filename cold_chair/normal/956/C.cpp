#include<cstdio>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(ll i = x; i <= y; i ++)
#define fd(i, x, y) for(ll i = x; i >= y; i --)
using namespace std;

const ll N = 2e5 + 5;

ll n, a[N], b[N], mx, ans;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%I64d", &n);
	fo(i, 1, n) scanf("%I64d", &a[i]);
	fd(i, n, 1) {
		mx --;
		b[i] = max(mx, a[i] + 1);
		mx = max(mx, a[i] + 1);
	}
	fo(i, 1, n) {
		mx = max(mx, a[i] + 1);
		ans += max(mx, b[i]) - a[i] - 1;
	}
	printf("%I64d", ans);
}