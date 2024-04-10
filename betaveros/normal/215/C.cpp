#include <cstdio>
using namespace std;

typedef long long int lli;

int m, n; // dimensions (obv. order doesn't matter)
int s; // area of cross

// darjn my variable names are so illiterate today

lli countPositions(int bdw, int bdh){
	// positions of a cross with bounding width and height given
	if (bdw > m || bdh > n) return 0;
	lli ret = ((lli)(m - bdw + 1)) * ((lli)(n - bdh + 1));
	// printf("%lld\n", ret);
	return ret;
}

lli countCrosses(){
	lli count = 0;
	// first we brute-force the wider / bigger rectangle, dubbed A
	// note that this algorithm fails to take advantage of any symmetry
	for (int awi = 0; (2*awi + 1) <= m; awi++){
		// printf("awi = %d\n", awi);
		int aw = 2*awi + 1; // actual width
		if (aw * n < s) continue; // target area too large, unattainable
		for (int ahi = 0; (2*ahi + 1) <= n; ahi++){
			// printf("ahi = %d\n", ahi);
			int ah = 2*ahi + 1;
			// printf("ahi = %d, ah = %d\n", ahi, ah);
			int aa = aw * ah; // area of A
			if (aa > s) break; // target area exceeded
			int excess = s - aa;
			// printf("excess = %d\n", excess);
			if (excess == 0){
				// printf("ahi = %d, ah = %d\n", ahi, ah);
				// any bounding area for b inside a works!
				// 0 <= bwi <= awi, 0 <= bhi <= ahi
				// note we can swap a and b in all except 1 of these cases!
				count += countPositions(aw, ah) * (lli) (2 * (awi+1) * (ahi+1) - 1);
			} else if (excess % 2 == 0) {
				// printf("even excess\n");
				// note that b's excess, being symmetric above
				// and below, must be even
				int half = excess / 2;
				// half = (2*bwi + 1) * (bhi-ahi)
				for (int bwi = 0; bwi < awi; bwi++){
					// bw[i] != aw[i] as that would be counted with ah larger
					int bw = 2*bwi + 1;
					if (half % bw == 0){ // fml boundcheck
						int bheh = half / bw;
						// always different, always swappable
						
						count += countPositions(aw, ah + 2*bheh) * (lli)(2);
					}
				}
			}
		}

	}
	return count;
}

int main(){
	scanf("%d %d %d", &m, &n, &s);
#ifdef ONLINE_JUDGE
	printf("%I64d", countCrosses());
#else
	printf("%lld", countCrosses());
#endif
}