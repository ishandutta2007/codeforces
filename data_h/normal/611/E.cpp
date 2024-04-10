#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define count C

const int N = 2e5 + 10;
const int INF = 1e9;

int a, b, c, n, cri[N];
int base = 0;
multiset<int> s;

int solve(int a, int b, int c, int ac, int bc, int abc) {
	int res = abc;
	res += bc;
	a = max(a - bc, 0);

	res += ac;
	if (b >= ac) {
		b -= ac;
	} else {
		a = max(a - (ac - b), 0);
		b = 0;
	}

	return res + max(c, max((c + b + 1) / 2, (a + b + c + 2) / 3));
}

int main() {
	scanf("%d", &n);
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	int v[11];
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = a + b;
	v[4] = a + c;
	v[5] = b + c;
	v[6] = a + b + c;
	sort(v, v + 7);

	vector<int> count(7, 0);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x > v[6]) {
			puts("-1");
			return 0;
		}
		for (int j = 0; j < 7; j++) {
			if (x <= v[j]) {
				count[j]++;
				break;
			}
		}
	}

	int answer = INF;
	for (int cnt = 0; cnt <= n; cnt++) {
		if (c < a + b) {
			answer = min(answer, cnt + solve(count[0], count[1], count[2], count[3] + count[4], count[5], count[6]));
		} else {
			answer = min(answer, cnt + solve(count[0], count[1], count[2] + count[3], count[4], count[5], count[6]));
		}

		for (int i = 2; i <= 3; i++) {
			for (int j = i; j >= 0; j--) {
				if (count[j] > 0) {
					count[j]--;
					break;
				}
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}