#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> a;
vector<pair<int, int> > pairs; 
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (!a.empty() && a.back() == x) {
			i--;
			m--;
		} else {
			a.push_back(x);
		}
	}
	if (m <= 1) {
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < m; i++) {
		pairs.push_back(make_pair(a[i], i));
	}
	sort(pairs.begin(), pairs.end());
	long long ans = 0, ccans = 0;
	for(int i = 1; i < m; i++) {
		ans += abs(a[i] - a[i - 1]);
	}
	for(int i = 0, j; i < m; i = j) {
		vector<int> numbers;
		for(j = i; j < m && pairs[j].first == pairs[i].first; j++) {
			int pos = pairs[j].second;
			if (pos > 0) {
				numbers.push_back(a[pos - 1]);
			}
			if (pos < m - 1) {
				numbers.push_back(a[pos + 1]);
			}
		}
		sort(numbers.begin(), numbers.end());
		int final = numbers[(int)numbers.size() / 2];
		long long cans = 0;
		for(int k = 0; k < (int)numbers.size(); k++) {
			cans += abs(numbers[k] - final);
			cans -= abs(numbers[k] - pairs[i].first);
		}
		ccans = min(ccans, cans);
	}
	cout << ans + ccans << endl;
}