#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1000000005;

const int N = 111111;

vector<pair<int, int> > points;
vector<pair<int, int> > cur, nxt;
int n, m;

void show(vector<pair<int, int> > &vec) {
	for(int i = 0; i < (int)vec.size(); i++) {
		printf("[%d %d] ", vec[i].first, vec[i].second);
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &n, &m);
	
	if (m == 0) {
		printf("%d\n", 2 * (n - 1));
		return 0;
	}
	
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points.push_back(make_pair(x, y));
	}
	
	sort(points.begin(), points.end());
	
	
	for(int i = 0; i < m; i++) {
		if (i == 0 || points[i].first != points[i - 1].first) {
			points.push_back(make_pair(points[i].first, n + 1));
		}
	}
	
	m = (int)points.size();
	sort(points.begin(), points.end());
	
	if (points[0].first == 1) {
		if (1 < points[0].second)
			cur.push_back(make_pair(1, points[0].second - 1));
	} else {
		cur.push_back(make_pair(1, n));
	}
	
	int lastX = 1;
	
	for(int j, i = 0; i < (int)points.size(); i = j) {
		if (points[i].first == 1) {
			j = i + 1;
			continue;
		}
		
		if (points[i].first - 1 > lastX) {
			int x = cur.begin()->first;
			cur.clear();
			cur.push_back(make_pair(x, n));	
		}
		
		nxt.clear();
		int last = 0;
		for(j = i; j < (int)points.size() && points[j].first == points[i].first; j++) {
			int r = points[j].second - 1;
			
			int left = 0, right = (int)cur.size() - 1, middle;
			while(left < right) {
				middle = (left + right) / 2;
				if (cur[middle].second > last)
					right = middle;
				else
					left = middle + 1;
			}
			
			int nl = max(cur[left].first, last + 1);
			if (cur[left].second > last && nl <= r)
				nxt.push_back(make_pair(nl, r));
			last = points[j].second;
		}
		
		cur = nxt;
		
		if ((int)cur.size() == 0) {
			printf("-1\n");
			return 0;
		}
		
		lastX = points[i].first;
		
		//show(cur);
		
	}
	
	if (lastX != n) {
		int x = cur.begin()->first;
		cur.clear();
		cur.push_back(make_pair(x, n));
	}
	
	for(int i = 0; i < (int)cur.size(); i++) {
		if (cur[i].first <= n && n <= cur[i].second) {
			printf("%d\n", 2 * n - 2);
			return 0;
		}
	}
	
	printf("-1\n");
	return 0;
}