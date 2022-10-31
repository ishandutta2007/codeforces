// http://codeforces.com/contest/1053/problem/B rewrite
#include <cstdio>
#include <algorithm>
using namespace std;
#define fori(i,s,e) for (int i = s; i < e; i++)

const int N = 300008;
int a[N];
int n;

int parityCount[2];

int main() {
	scanf("%d", &n);
	int csum = 0;
	parityCount[csum%2]++;
	long long goodParityRanges = 0;
	fori (i, 0, n) {
		long long x;
		scanf("%lld", &x);
		a[i] = __builtin_popcountll(x);
		csum += a[i];
		goodParityRanges += parityCount[csum%2];
		parityCount[csum%2]++;
	}

	fori (i, 0, n) {
		int curmax = 0;
		int cursum = 0;
		fori (j, i, i + 150) {
			if (j >= n) break;

			curmax = max(curmax, a[j]);
			cursum += a[j];
			
			if (cursum % 2 == 0 && 2*curmax > cursum) {
				goodParityRanges--;
			}
		}
	}

	printf("%lld\n", goodParityRanges);
}