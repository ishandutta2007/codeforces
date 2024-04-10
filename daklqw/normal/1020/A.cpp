#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, h, a, b, k;
int ta, fa, tb, fb;
int ans;
int abs(int a) {return a > 0 ? a : -a;}
int main() {
	scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);//a<=b
	while (k --> 0) {
		scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
		ans = 0;
//		if (fa >= b) {
//			if (fb >= b) ans = fa - b + fb - b;
//			else {
//				ans = fa - fb;
//			}
//		} else {
//			if (fa >= a) {
//				if (fb >= b) ans = fb - fa;
//				else if (fb >= a) ans = abs(fa - fb);
//					else ans = 
//			}
//		}
		if (ta == tb) ans = abs(fa - fb);
		else {
			if (fa > b && fb > b) {
				ans = fa - b + fb - b;
			} else {
				if (fa < a && fb < a) {
					ans = a - fa + a - fb;
				} else ans = abs(fa - fb);
			}
		}
		ans = ans + abs(ta - tb);
		printf("%d\n", ans);
	}
	return 0;
}