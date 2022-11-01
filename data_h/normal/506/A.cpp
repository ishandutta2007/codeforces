#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 33333;

int n, d;
vector<pair<int, int> > f[N];
int gems[N];

int main() {
	scanf("%d %d", &n, &d);
	for(int i = 1; i <= n; i++) {
		int p;
		scanf("%d", &p);
		gems[p]++;
	}
	f[d].push_back(make_pair(d, gems[d]));
	int answer = 0;
	for(int i = d; i <= 30000; i++) {
		sort(f[i].begin(), f[i].end());
		for(int j = 0, k; j < (int)f[i].size(); j = k) {
			int maxV = -1, dist = f[i][j].first;
			for(k = j; k < (int)f[i].size() && f[i][j].first == f[i][k].first; k++) {
				maxV = f[i][k].second;
			}
			answer = max(answer, maxV);
			for(int delta = -1; delta <= 1; delta++) {
				if (delta + dist > 0 && i + delta + dist <= 30000) {
					f[i + delta + dist].push_back(make_pair(delta + dist, maxV + gems[i + delta + dist]));
				}
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}