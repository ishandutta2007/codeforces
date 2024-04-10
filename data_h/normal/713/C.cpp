#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

const int N = 3333;

using namespace std;

int n;
int a[N];
long long f[N];

pair<int, vector<int> > stack[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		v.push_back(a[i]);
		stack[s++] = make_pair(a[i], v);
		while (s >= 2 && stack[s - 1].first < stack[s - 2].first) {
			for (auto x : stack[s - 1].second) {
				stack[s - 2].second.push_back(x);
			}
			stack[s - 1].second.clear();
			s--;
			sort(stack[s - 1].second.begin(), stack[s - 1].second.end());
			stack[s - 1].first = stack[s - 1].second[stack[s - 1].second.size() / 2];
		}
	}

	long long answer = 0;
	for (int i = 0, tot = 0; i < s; i++) {
		for (int j = 0; j < stack[i].second.size(); j++) {
			answer += abs(stack[i].first - a[++tot]);
		}
	}
	printf("%lld\n", answer);
	return 0;
}