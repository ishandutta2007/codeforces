#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 111;

int n, m;
vector<pair<int, int> > points;
vector<pair<int, int> > ans, cur;
double result = -1;

int dx[] = {0, 1, 0, 1};
int dy[] = {0, 1, 1, 0};
 
void print(int x, int y) {
	printf("%d %d\n", x, y);
}

int inRange(int x, int y) {
	return x >= 0 && x <= n && y >= 0 && y <= m;
}

void push(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (inRange(xx, yy)) {
			points.push_back(make_pair(xx, yy));
		}
	}
}

int visit[N];

double dist(pair<int, int> a, pair<int, int> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void dfs(int d, double r, int last) {
	if (d == 4) {
		if (r > result) {
			result = r;
			ans = cur;
		}
		return ;
	}
	for(int i = 0; i < (int)points.size(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			cur.push_back(points[i]);
			if (last != -1) {
				dfs(d + 1, r + dist(points[last], points[i]), i);
			} else {
				dfs(d + 1, r, i);
			}
			cur.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	push(0, 0);
	push(n - 1, 0);
	push(n - 1, m - 1);
	push(0, m - 1);
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	dfs(0, 0, -1);
	for(int i = 0; i < 4; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}