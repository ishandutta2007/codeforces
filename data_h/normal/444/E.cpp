#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

vector<pair<int, pair<int, int> > > edges;
int n;
int father[N], c[N], size[N], s = 0;
int one = 1;
int find(int a) {
	return father[a] == a ? a : father[a] = find(father[a]);
}

int mergy(int a, int b) {
	father[a] = b;
	size[b] += size[a];
	c[b] += c[a];
	if (size[b] > size[one]) {
		one = b;
	}
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for(int i = 1; i < n; i++)	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(edges.begin(), edges.end());
	for(int i = 1; i <= n; i++) {
		father[i] = i;
		scanf("%d", &c[i]);
		size[i] = 1;
		s += c[i];
	}
	int ans = edges[0].first;
	one = 1;
	for(int i = 0, j; i < n - 1; i = j) {
		for(j = i; j < n - 1 && edges[j].first == edges[i].first; j++) {
			int a = find(edges[j].second.first), b = find(edges[j].second.second);
			mergy(a, b);
		}
		if (s - c[one] >= size[one] && j < n) {
			ans = edges[j].first;
		}
	}
	printf("%d\n", ans);
	return 0;
}