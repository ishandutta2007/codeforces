#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = (1 << 17);

int n;
int degree[N], xs[N];
bool finished[N];

int main() {
	scanf("%d", &n);
	priority_queue<pair<int, int> > q;
	vector<pair<int, int> > edges;

	for(int i = 0; i < n; i++) {
		int d, s;
		scanf("%d %d", &d, &s);
		q.push(make_pair(-d, i));
		degree[i] = d;
		xs[i] = s;
		finished[i] = false;
	}

	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (finished[x]) {
			continue;
		}
		finished[x] = true;

		if (degree[x] == 0) {
			continue;
		}
		// degree[x] must be 1
		int y = xs[x];
		edges.push_back(make_pair(x, y));
		xs[y] ^= x;
		q.push(make_pair(-(--degree[y]), y));
	}
	printf("%d\n", (int)edges.size());
	for(int i = 0; i < (int)edges.size(); i++) {
		printf("%d %d\n", edges[i].first, edges[i].second);
	}
	return 0;
}