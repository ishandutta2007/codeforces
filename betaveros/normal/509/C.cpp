// @betaveros :: generated with cpp2.hs
#include <algorithm>
#include <cstdio>
using namespace std;
int digs[1337];
int len = 0;


bool fillSum(int i1, int tgt) {
	if (tgt < 0 || tgt > 9 * (len - i1)) return false;
	for (int i = i1; i < len; ++i){ digs[i] = 0; }
	int j = len - 1;
	while (tgt){
		int d =min(tgt, 9);
		digs[j--] = d;
		tgt -= d;
	}
	return true;
}

void next(int x) {
	int s = 0;
	for (int i = 0; i < len; ++i){ s += digs[i]; }
	int j = len - 1;
	while (j >= 0){
		while (digs[j] < 9){
			digs[j]++;
			s++;
			if (fillSum(j + 1, x - s)){
				return;
			}
		}
		--j;
		s -= 9;
	}
	len = max(len + 1, (x+8) / 9);
	fillSum(0, x - 1);
	digs[0] += 1;
}

int main() {
	int n; scanf("%d", &n);
	for (int _t0 = n; _t0 > 0; --_t0){
		int x; scanf("%d", &x);
		next(x);
		for (int j = 0; j < len; ++j){ printf("%d", digs[j]); }
		printf("\n");
	}
}