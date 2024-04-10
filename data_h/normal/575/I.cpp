#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 7;

int n, q;
const int DEBUG = 0;

struct Node {
	int dir;
	int x, y, len, idx;
	Node(int dir, int x, int y, int len) : dir(dir), x(x), y(y), len(len) {}
	friend bool operator ==(const Node &a, const Node &b) {
		return a.dir == b.dir && a.x == b.x && a.y == b.y && a.len == b.len;
	}
};

struct Info {
	int x, y, id;
	Info(int x, int y, int id) : x(x), y(y), id(id) {}
	friend bool operator <(const Info &a, const Info &b) {
		return a.y < b.y;		
	}
};

vector<Node> queries;
int answer[N];

vector<Node> events; 
vector<Info> infos;
vector<int> junk;

int h[N];

inline int lowbit(int x) {
	return x & (-x);
}

int bigger(const vector<int>& a, int v) {
	return a.end() - upper_bound(a.begin(), a.end(), v);
}

void inc(int pos) {
	for (int i = pos; i <= n; i += lowbit(i)) {
		h[i] ++;
	}
	junk.push_back(pos);
}

void clear() {
	for (int i = 0; i < (int)junk.size(); i++) {
		int p = junk[i];
		for (int j = p; j <= n; j += lowbit(j)) {
			h[j] = 0;
		}
	}
	junk.clear();
}

int ask(int pos) {
	int ret = 0;
	for (int i = pos; i; i -= lowbit(i)) {
		ret += h[i];
	}
	return ret;
}

void fuck() {
	junk.clear();
	static vector<int> values;
	values.clear();
	for (int i = 0; i < infos.size(); i++) {
		infos[i].x = -infos[i].x;
		infos[i].y = -infos[i].y;
		values.push_back(infos[i].x);
	}

	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	n = values.size();
	for (int i = 0; i < infos.size(); i++) {
		infos[i].x = lower_bound(values.begin(), values.end(), infos[i].x) - values.begin() + 1;
	}

	sort(infos.begin(), infos.end());
	for (int i = 0, j; i < (int)infos.size(); i = j) {
		//cout << "i = " << i << endl;
		for (j = i; j < (int)infos.size() && infos[j].y == infos[i].y; j++) {
			if (infos[j].id >= 0) {
				answer[infos[j].id] += ask(infos[j].x - 1);
			}
		}
		for (int k = i; k < j; k++) {
			if (infos[k].id == -1) {
				inc(infos[k].x);
			}
		}
	}

	clear();
}

void solve() {
	int total = 0;
	int m = events.size();

	// A  B  C = 0
	
	for (int i = 0; i < m; i++) {
		if (events[i].dir != 0) {
			total++;
		}
	}

	static vector<int> values;
	{
		values.clear();
		for (int i = 0; i < m; i++) {
			if (events[i].dir != 0) {
				values.push_back(events[i].x);
			}
		}
		sort(values.begin(), values.end());
		for (int i = 0; i < m; i++) {
			if (events[i].dir == 0) {
				answer[events[i].idx] -= bigger(values, events[i].x);
			}
		}
	}

	{
		values.clear();
		for (int i = 0; i < m; i++) {
			if (events[i].dir != 0) {
				values.push_back(events[i].y);
			}
		}
		sort(values.begin(), values.end());
		for (int i = 0; i < m; i++) {
			if (events[i].dir == 0) {
				answer[events[i].idx] -= bigger(values, events[i].y);
			}
		}
	}

	{
		values.clear();
		for (int i = 0; i < m; i++) {
			if (events[i].dir != 0) {
				int t = events[i].x + events[i].y + events[i].len;
				values.push_back(-t);
				//cout << events[i].x << " " << events[i].y << " " << events[i].len << endl;
			}
		}
		sort(values.begin(), values.end());
		for (int i = 0; i < m; i++) {
			if (events[i].dir == 0) {
				int t = events[i].x + events[i].y;
				answer[events[i].idx] -= bigger(values, -t);
				//cout << "?? " << t << endl;
			}
		}
	}

	{
		infos.clear();
		for (int i = 0; i < m; i++) {
			if (events[i].dir != 0) {
				infos.push_back(Info(events[i].x, events[i].y, -1));
			} else {
				infos.push_back(Info(events[i].x, events[i].y, events[i].idx));
			}
		}
		fuck();
	}

	{
		infos.clear();
		for (int i = 0; i < m; i++) {
			int t = events[i].x + events[i].y + events[i].len;
			if (events[i].dir != 0) {
				infos.push_back(Info(events[i].x, -t, -1));
			} else {
				infos.push_back(Info(events[i].x, -t, events[i].idx));
			}
		}
		fuck();
	}

	{
		infos.clear();
		for (int i = 0; i < m; i++) {
			int t = events[i].x + events[i].y + events[i].len;
			if (events[i].dir != 0) {
				infos.push_back(Info(-t, events[i].y, -1));
			} else {
				infos.push_back(Info(-t, events[i].y, events[i].idx));
			}
		}
		fuck();
	}

	for (int i = 0; i < m; i++) {
		if (events[i].dir == 0) {
			answer[events[i].idx] += total;
		}
	}
}

void divide(int l, int r) {
	if (l == r) {
		return ;
	}
	int mid = (l + r) / 2;
	divide(l, mid);
	divide(mid + 1, r);
	for (int dir = 1; dir <= 4; dir++) {
		// dir
		events.clear();
		for (int i = l; i <= mid; i++) {
			if (queries[i].dir == dir) {
				events.push_back(queries[i]);
			}
		}

		if (events.size() == 0) {
			continue;
		}
		int tmp = events.size();

		for (int i = mid + 1; i <= r; i++) {
			if (queries[i].dir == 0) {	
				events.push_back(queries[i]);
			}
		}
		
		if (events.size() == tmp) {
			continue;
		}

		for (int i = 0; i < (int)events.size(); i++) {
			if (dir == 3 || dir == 4) {
				events[i].x = -events[i].x;
			}
			if (dir == 2 || dir == 4) {
				events[i].y = -events[i].y;
			}
		}
		solve();
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int type, dir, x, y, len;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d %d %d %d", &dir, &x, &y, &len);
		} else {
			scanf("%d %d", &x, &y);
			dir = len = 0;
		}
		queries.push_back(Node(dir, x, y, len));
		queries.back().idx = i;
	}
	divide(0, q - 1);

	for (int i = 0; i < q; i++) {
		if (queries[i].dir == 0) {
			printf("%d\n", answer[i]);
		}
	}
	return 0;
}