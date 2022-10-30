// @betaveros :: generated with cpp2.hs
#include <cstdio>
using namespace std;
int n, k, odds, evens;
const char * stannis = "Stannis";
const char * daenerys = "Daenerys";
int main() {
	scanf("%d%d", &n, &k);
	for (int _t0 = n; _t0 > 0; --_t0){
		int x; scanf("%d", &x);
		if (x % 2){ odds++; } else { evens++; }
	}
	int sTurns = (n - k + 1) / 2;
	int dTurns = (n - k) / 2;
	if (n == k){
		puts(odds % 2 ? stannis : daenerys);
		return 0;
	}
	if (k % 2){
		if (sTurns >= evens) {
			puts(stannis);
			return 0;
		}
		if (dTurns >= odds) {
			puts(daenerys);
			return 0;
		}
	} else {
		if (dTurns >= evens || dTurns >= odds) {
			puts(daenerys);
			return 0;
		}
	}
	puts((n - k) % 2 ? stannis : daenerys);
}