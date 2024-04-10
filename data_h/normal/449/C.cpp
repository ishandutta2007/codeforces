#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

vector<pair<int, int> > ans;
int used[N], factor[N];
int n;

int main() {
	scanf("%d", &n);
	vector<int> vec;
	for(int i = 2; i <= n; i++) {
		factor[i] = i;
	}
	for(int i = 2; i <= n; i += 2) {
		if (factor[i] == i) {
			for(int j = i; j <= n; j += i) {
				factor[j] = i;
			}
		}
	}
	for(int i = n; i >= 1; i--) {
		if (factor[i] == i) {
			vector<int> vec;
			for(int j = i; j <= n; j += i) {
				if (!used[j]) {
					vec.push_back(j);
				}
			}
			if (vec.size() == 1) {
				continue;
			}
			if (vec.size() % 2 == 1) {
				swap(vec[1], vec.back());
			}
			for(int j = 1; j < (int)vec.size(); j += 2) {
				ans.push_back(make_pair(vec[j - 1], vec[j]));
				used[vec[j - 1]] = used[vec[j]] = 1;
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}