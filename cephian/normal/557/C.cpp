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

using namespace std;
typedef pair<int, int> pii;

int n;

pii legs[100000];

//frequency of costs
int frq[201];
//frequency of legs by length
int leg_frq[100001];
//cfr on sum of cost of legs by length
int cfr[100001];
//cfr on amt of legs
int cfr_amt[100001];

int main() {
	ios::sync_with_stdio(0);

	fill(frq, frq + 201, 0);
	fill(cfr, cfr + 100001, 0);
	fill(leg_frq, leg_frq + 100001, 0);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &legs[i].first);
		++leg_frq[legs[i].first];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &legs[i].second);
		cfr[legs[i].first] += legs[i].second;
	}
	for (int i = 1; i < 100001; ++i)
		cfr[i] += cfr[i - 1];

	cfr_amt[0] = leg_frq[0];
	for (int i = 1; i < 100001; ++i)
		cfr_amt[i] = cfr_amt[i - 1] + leg_frq[i];

	sort(legs, legs + n);
	int last = -1;

	int ans = 1e9;

	for (int i = 0; i < n; ++i) {
		if (legs[i].first != last) {
//			printf("testing on %d\n", i);

			last = legs[i].first;
			int t_ans = cfr[100000] - cfr[legs[i].first];

			int tmp_n = n - (cfr_amt[100000] - cfr_amt[legs[i].first]);

//			printf("%d : %d\n", t_ans, tmp_n);

			if (t_ans < ans) {
				int maxn = leg_frq[legs[i].first] * 2 - 1;
				for (int j = 1; j <= 200; ++j) {
					if (tmp_n <= maxn)
						break;
					if (tmp_n - frq[j] >= maxn) {
						tmp_n -= frq[j];
						t_ans += j * frq[j];
					} else {
//						printf("adding to %d\n", t_ans);
						t_ans += (tmp_n - maxn) * j;
						break;
					}
				}
//				printf("-->%d\n", t_ans);
				ans = min(ans, t_ans);
			}
		}
		++frq[legs[i].second];
	}

	printf("%d\n", ans);

	return 0;
}