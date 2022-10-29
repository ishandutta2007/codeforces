#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	int n, v;
	cin >> n >> v;
	vector < pair<int,int> > a[2];
	for (int i=0; i<n; ++i) {
		int t, p;
		scanf ("%d%d", &t, &p);
		a[t-1].push_back (make_pair (p, i));
	}
	sort (a[0].begin(), a[0].end());
	sort (a[1].begin(), a[1].end());
	reverse (a[0].begin(), a[0].end());
	reverse (a[1].begin(), a[1].end());

	long long sum1 = 0,  sum2 = 0,  ans = -1;
	int bestc1, bestc2;
	for (int c1=0, c2=0, cv=0; c1<=(int)a[0].size(); ++c1) {
		while (cv+2 <= v && c2 < (int)a[1].size()) {
			cv += 2;
			sum2 += a[1][c2++].first;
		}
		while (cv > v && c2 > 0) {
			cv -= 2;
			sum2 -= a[1][--c2].first;
		}
		if (cv <= v)
			if (sum1 + sum2 > ans) {
				ans = sum1 + sum2;
				bestc1 = c1;
				bestc2 = c2;
			}
		if (c1 < (int) a[0].size()) {
			sum1 += a[0][c1].first;
			cv += 1;
		}
	}

	cout << ans << endl;
	for (int i=0; i<bestc1; ++i)
		printf ("%d ", a[0][i].second+1);
	for (int i=0; i<bestc2; ++i)
		printf ("%d ", a[1][i].second+1);

}