#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int q; ll l, r, s;

int main() {
	for(scanf("%d", &q); q; q --) {
		scanf("%I64d %I64d", &l, &r);
		s = 0;
		ll l0 = l + (l & 1), r0 = r - (r & 1);
		if(l0 <= r0) s += (l0 + r0) * ((r0 - l0) / 2 + 1) / 2;
		l0 = l + (!(l & 1)), r0 = r - (!(r & 1));
		if(l0 <= r0) s -= (l0 + r0) * ((r0 - l0) / 2 + 1) / 2;
		printf("%I64d\n", s);
	}
}