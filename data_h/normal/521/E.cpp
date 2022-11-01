#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

const int N = 222222;

vector<int> e[N];
vector<pair<int, int> > edges;
int n, m;
vector<int> block[N << 1];
int mark[N], tag = 0;

/*
color
*/

int global_c; // n
vector<pair<int, int> > along;
vector<int> stack;
int color[N];

void gabow(int x, int father) {
	stack.push_back(x);
	color[x] = stack.size();
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (!color[y]) {
			along.push_back(make_pair(color[x], stack.size() + 1));
			gabow(y, x);
		} else {
			while(!along.empty() && along.back().first > color[y]) {
				along.pop_back();
			}
		}
	}
	if(color[x] == 1) {
		color[x] = global_c;
	} else {
		if (along.empty()) {
			return ;
		}
		if (along.back().second == color[x]) {
			along.pop_back();
			color[x] = ++global_c;
			while(stack.back() != x) {
				color[stack.back()] = global_c;
				stack.pop_back();
			}
			stack.pop_back();
		}
	}
}

vector<int> path;
int inPath[N], source, target;

bool dfs(int x, int from) {
	inPath[x] = true;
	path.push_back(x);
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == from || mark[y] != tag) {
			continue;
		} else if (!inPath[y]) {
			if (dfs(y, x)) {
				return true;
			}
		} else {
			path.push_back(y);
			return true;
		}
	}
	path.pop_back();
	inPath[x] = false;
	return false;
}

vector<int> findCycle(int start) {
	path.clear();
	if (!dfs(start, -1)) {
		return vector<int>();
	}
	vector<int> ret;
	for(int i = (int)path.size() - 2; i >= 0; i--) {
		ret.push_back(path[i]);
		if (path[i] == path.back()) {
			break;
		}
	}
	for(int i = 0; i < (int)path.size(); i++) {
		inPath[path[i]] = false;
	}
	return ret;
}

int visit[N], cur = 0;

vector<int> answer[3];

int findTarget(int x) {
	if (x == source) {
		return 0;
	}
	answer[0].push_back(x);
	if (mark[x] == tag) {
		return x;
	}
	visit[x] = cur;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (mark[y] >= tag - 1 && visit[y] != cur) {
			int tmp = findTarget(y);
			if (tmp) {
				return tmp;
			}
		}
	}
	answer[0].pop_back();
	return 0;
}

void yes() {
	puts("YES");
	for(int j = 0; j < 3; j++) {
		printf("%d ", (int)answer[j].size());
		for(int k = 0; k < (int)answer[j].size(); k++) {
			printf("%d%c", answer[j][k], k == (int)answer[j].size() - 1 ? '\n' : ' ');
		}
	}
	exit(0);
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	return min(color[a.first], color[a.second]) < min(color[b.first], color[b.second]);
}

int main() {
	scanf("%d %d", &n, &m);
	global_c = n;
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
		edges.push_back(make_pair(a, b));
	}
	for(int i = 1; i <= n; i++) {
		if (!color[i]) {
			gabow(i, -1);
		}
	}
	for(int x = 1; x <= n; x++) {
		for(int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i];
			int id = min(color[x], color[y]);
			block[id].push_back(x);
			block[id].push_back(y);
		}
	}
	
	sort(edges.begin(), edges.end(), compare);
	for(int i = 1; i <= n; i++) {
		e[i].clear();
	}
	
	for(int i = 1, ptr = 0; i <= global_c; i++) {
		vector<int> tmp = block[i];
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		if (tmp.empty()) {
			continue;
		}
		
		while (ptr < (int)edges.size() && min(color[edges[ptr].first], color[edges[ptr].second]) == i) {
			e[edges[ptr].first].push_back(edges[ptr].second);
			e[edges[ptr].second].push_back(edges[ptr].first);
			ptr++;
		}
		
		++tag;
		for(int j = 0; j < (int)tmp.size(); j++) {
			mark[tmp[j]] = tag;
		}
		vector<int> cycle = findCycle(tmp[0]);
		int m = (int)cycle.size();
		++tag;
		for(int j = 0; j < m; j++) {
			mark[cycle[j]] = tag;
		}
		for(int j = 0; j < m; j++) {
			int x = cycle[j];
			for(int k = 0; k < (int)e[x].size(); k++) {
				int y = e[x][k];
				if (mark[y] < tag - 1 || y == cycle[(j + 1) % m] || y == cycle[(j + m - 1) % m]) {
					continue;
				}
				++cur;
				source = x, target = findTarget(y);
				answer[0].insert(answer[0].begin(), source);
				for(int p = j; cycle[p] != target; p = (p + 1) % m) {
					answer[1].push_back(cycle[p]);
				}
				answer[1].push_back(target);
				for(int p = j; cycle[p] != target; p = (p - 1 + m) % m) {
					answer[2].push_back(cycle[p]);
				}
				answer[2].push_back(target);
				yes();
			}
		}
		
		for(int j = 0; j < (int)tmp.size(); j++) {
			e[tmp[j]].clear();
		}
	}
	puts("NO");
	return 0;
}