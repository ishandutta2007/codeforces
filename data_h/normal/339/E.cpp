#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1100;

int n, a[N];
vector<pair<int, int> > answer;
int cnt[N], tot;

__inline void fresh(int pos) {
	tot -= cnt[pos];
	cnt[pos] = abs(a[pos] - a[pos + 1]) == 1;
	tot += cnt[pos];
}

void rev(int l, int r, int flag) {
	for (int i = l, j = r; i < j; i++, j--) {
		swap(a[i], a[j]);
	}
	for (int i = l - 1; i <= r; i++) {
		fresh(i);
	}
	if (flag == 1) {
		answer.push_back(make_pair(l, r));
	} else {
		answer.pop_back();
	}
}

void shrink(int &l, int &r) {
	while (l < r && a[l] == l) l++;
	while (l < r && a[r] == r) r--;
}

void show_answer() {
	printf("%d\n", answer.size());
	for (int i = answer.size() - 1; i >= 0; i--) {
		printf("%d %d\n", answer[i].first, answer[i].second);
	}
	exit(0);
}

void dfs(int times, int l, int r) {
	if (tot == n + 1) {
		show_answer();
		return ;
	}

	if (tot < n + 1 - 2 * times) return ;
	shrink(l, r);
	if (tot >= n - times) {
		// cout << times << " " << n + 1 - tot << endl;
		// for (int i = l - 1; i <= r; i++) {
		// 	if (abs(a[i] - a[i + 1]) != 1) {
		// 		printf("sep pos = %d  %d, %d\n", i, a[i], a[i + 1]);
		// 	}
		// }
		// one of following 2 cases must be true.
		for (int i = l + 1; i <= r; i++) {
			if (a[i] == l && a[i + 1] != l + 1) {
				//cout << "--- " << times << endl;
				rev(l, i, 1);
				dfs(times - 1, l, r);
				rev(l, i, -1);
				//return ;
			}
		}
		for (int i = r - 1; i >= l; i--) {
			if (a[i] == r && a[i - 1] != r - 1) {
				//cout << "--- " << times << endl;
				rev(i, r, 1);
				dfs(times - 1, l, r);
				rev(i, r, -1);
				//return ;
			}
		}
		//return ;
	}

	if (tot == n - 1) {
		answer.push_back(make_pair(l, r));
		show_answer();
		return ;
	}

	rev(l, r, 1);
	dfs(times - 1, l, r);
	rev(l, r, -1);

	vector<pair<int, int> > pairs;
	for (int ll = l; ll <= r; ll++) {
		if (abs(a[ll - 1] - a[ll]) == 1) continue;
		for (int rr = ll; rr <= r; rr++) {
			bool flag = false;
			if (abs(a[rr] - a[rr + 1]) > 1) {
				flag = true;
			} else {
				flag = (abs(a[ll - 1] - a[rr]) == 1 && abs(a[rr + 1] - a[ll]) == 1);
			}
			if (flag) pairs.push_back(make_pair(ll, rr));
		}
	}
	for (int rr = l; rr <= r; rr++) {
		if (abs(a[rr + 1] - a[rr]) == 1) continue;
		for (int ll = l; ll <= rr; ll++) {
			bool flag = false;
			if (abs(a[ll] - a[ll - 1]) == 1) {
				flag = (abs(a[ll - 1] - a[rr]) == 1 && abs(a[rr + 1] - a[ll]) == 1);
			}
			if (flag) pairs.push_back(make_pair(ll, rr));
		}
	}

	for (int i = 0; i < pairs.size(); i++) {
		if (l <= pairs[i].first && pairs[i].second <= r) {
			rev(pairs[i].first, pairs[i].second, 1);
			dfs(times - 1, l, r);
			rev(pairs[i].first, pairs[i].second, -1);
		}
	}
}

int main() {
	scanf("%d", &n);
//	n = 1000;
	// for (int i = 1; i <= n; i++) a[i] = i;
	// for (int i = 1, j = 500; i < j; i++, j--) swap(a[i], a[j]);
	// for (int i = 1, j = 999; i < j; i++, j--) swap(a[i], a[j]);
	// for (int i = 1, j = 499; i < j; i++, j--) swap(a[i], a[j]);
	tot = 0;
	fill(cnt + 1, cnt + n + 1, 0);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[0] = 0, a[n + 1] = n + 1;
	for (int i = 0; i <= n; i++) fresh(i);

	dfs(3, 1, n);
	cout << "fuck you" << endl;
	return 0;
}