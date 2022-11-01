#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

typedef std::pair<int, int> Pair;

int n;
std::vector<std::pair<int, int> > s;

long long val[2] = {0};
int cur = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, A, B;
		scanf("%d %d %d %d", &a, &b, &A, &B);
		if (a + b < A + B) {
			if (a - B < 0 && b - A < 0) {
				continue;
			} else {
				if (a - B > b - A) {
					val[0] += a - B;
				} else {
					val[1] += b - A;
				}
				//s.push_back(std::make_pair(a - B, b - A));
			}
		} else {
			s.push_back(std::make_pair(a, b));
			s.push_back(std::make_pair(A, B));
		}
	}
	sort(s.begin(), s.end(), [&](const Pair &a, const Pair &b) {
		return a.first + a.second < b.first + b.second;
	});
	for (int i = s.size() - 1; i >= 0; i--) {
		val[cur] += (cur == 0 ? s[i].first : s[i].second);
		cur ^= 1;
	}
	std::cout << val[0] - val[1] << std::endl;
	return 0;
}