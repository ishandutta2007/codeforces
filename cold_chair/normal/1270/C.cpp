#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int T;
int n;
int a[N];
ll s1, s2, x;

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		s1 = s2 = 0;
		fo(i, 1, n) {
			s1 += a[i];
			s2 ^= a[i];
		}
		x = 0;
		s2 *= 2;
		fo(i, 0, 60) {
			if((s1 >> i & 1) != (s2 >> i & 1)) {
				x += 1ll << i;
				s1 += 1ll << i;
				s2 ^= 1ll << (i + 1);
			}
		}
		pp("1\n%lld\n", x);
		
//		s1 = x, s2 = x;
//		fo(i, 1, n) s1 += a[i], s2 ^= a[i];
//		pp("%lld %lld\n", s1, s2 * 2);
	}
}