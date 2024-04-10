// http://codeforces.com/problemset/problem/1137/A
// 3:41
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define fori(i,s,e) for (int i = s; i < e; i++)

const int N = 1008;
int heights[N][N];
int heightsT[N][N];
int nRows, nCols;

typedef struct Pair {
	int index;
	int value;
	bool operator<(const Pair & other) const {
		return value < other.value;
	}
} Pair;

void solve(int a[], int len, int under[], int over[]) {
	// under[i] is how many numbers are under a[i]
	// over[i] is how many numbers are over a[i]
	vector<Pair> vec;
	fori (i, 0, len) {
		vec.push_back((Pair) { .index = i, .value = a[i] });
	}
	sort(vec.begin(), vec.end());
	int lastValue = -1;
	int currentUnder = 0;
	for (const auto & p : vec) {
		if (lastValue != -1 && lastValue < p.value) {
			currentUnder++;
		}
		under[p.index] = currentUnder;
		lastValue = p.value;
	}
	// currentUnder is number of numbers - 1
	fori (i, 0, len) {
		over[i] = currentUnder - under[i];
	}
}

int over[N][N];
int overT[N][N];
int under[N][N];
int underT[N][N];

int main() {
	scanf("%d%d", &nRows, &nCols);
	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			int x;
			scanf("%d", &x);
			heights[i][j] = x;
			heightsT[j][i] = x;
		}
	}

	fori (i, 0, nRows) {
		solve(heights[i], nCols, under[i], over[i]);
	}
	fori (i, 0, nCols) {
		solve(heightsT[i], nRows, underT[i], overT[i]);
	}

	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			if (j) {
				putchar(' ');
			}
			printf("%d", max(under[i][j], underT[j][i]) + max(over[i][j], overT[j][i]) + 1);
		}
		puts("");
	}
}