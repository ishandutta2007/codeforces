#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long ll;

int cdiv[5000002];

void genp() {
	fill(cdiv, cdiv + 5000002, 0);
	for (ll i = 2; i <= 5000000; ++i) {

		if (cdiv[i] == 0) {
			cdiv[i] = i;
			if (i * i <= 5000000) {
				for (int j = i * i; j <= 5000000; j += i) {
					cdiv[j] = i;
				}
			}
		}
	}
}

int ans[5000001];
int factors[5000001];

void g1() {
	factors[1] = 0;
	for (int i = 2; i <= 5000000; ++i) {
		factors[i] = 1 + factors[i / cdiv[i]];
	}
}

void g2() {
	ans[1] = 0;
	for (int i = 2; i <= 5000000; ++i) {
		ans[i] = ans[i - 1] + factors[i];
	}
}

int main() {

	genp();
	g1();
	g2();
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[a] - ans[b]);
	}

	return 0;
}