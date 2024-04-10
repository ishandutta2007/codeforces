#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500008;
const int K = 5008;
int a[N];
int n, k;

const int OO = 1000000009;


typedef struct Gap {
	int i;
	int w;
	bool operator<(const Gap & other) const {
		if (w != other.w) return w < other.w;
		return i < other.i;
	}
} Gap;
bool icmp(const Gap & a, const Gap & b) { return a.i < b.i; }

vector<Gap> gaps;

int finalGaps[N];

int dp[3][K];

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	for (int i = 0; i < n-1; i++) {
		gaps.push_back((Gap) { .i = i, .w = a[i+1] - a[i] });
	}
	sort(gaps.begin(), gaps.end());

	// coalesce all gaps that > big
	Gap big;
	big.w = OO;
	if (gaps.size() >= 3*k) {
		big = gaps[3*k-1];
	}
	sort(gaps.begin(), gaps.end(), icmp);

	int fi = 0;
	for (const Gap & gap : gaps) {
		if (big < gap) {
			// only add if previous wasn't also huge
			if (fi == 0 || finalGaps[fi - 1] < OO) {
				finalGaps[fi] = OO;
				fi++;
			}
		} else {
			finalGaps[fi] = gap.w;
			fi++;
		}
	}

	// dp[i%3][s]: s meetings in first i gaps
	for (int i = 0; i <= 1; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = OO;
		}
	}
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[1][1] = finalGaps[0];

	for (int i = 2; i <= fi; i++) {
		// current gap is finalGaps[i-1]
		for (int j = 0; j <= k; j++) {
			dp[i%3][j] = dp[(i-1)%3][j];
			if (j) {
				dp[i%3][j] = min(
					dp[i%3][j],
					dp[(i-2)%3][j-1] + finalGaps[i-1]
				);
			}
		}
	}

	printf("%d\n", dp[fi%3][k]);
}