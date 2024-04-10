#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 111111;

int n, source, target, from[N];
vector<pair<int, int> > e[N];
long long dist[N], farest[N];

void dfs(int x, long long ds, int &reach) {
	dist[x] = ds;
	if (reach == -1 || dist[reach] < dist[x]) {
		reach = x;
	}

	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		int length = e[x][i].second;
		if (y == from[x]) {
			continue;
		}

		from[y] = x;
		dfs(y, ds + length, reach);
	}
}

void go(int x, long long ds) {
	farest[x] = max(farest[x], ds);
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		int length = e[x][i].second;
		if (y == from[x]) {
			continue;
		}
		from[y] = x;
		go(y, ds + length);
	}
}

int father[N], size[N];

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	source = -1;
	from[1] = -1;
	dist[1] = 0;
	dfs(1, 0, source);
	
	target = -1;
	from[source] = -1; 
	dist[source] = 0;
	dfs(source, 0, target);

	//cout << "source = " << source << " target = " << target << endl;


	fill(farest + 1, farest + n + 1, 0);
	from[source] = -1, go(source, 0);
	from[target] = -1, go(target, 0);

	vector<pair<long long ,int> > orders;
	for(int i = 1; i <= n; i++) {
		orders.push_back(make_pair(farest[i], i));
	}	

	sort(orders.begin(), orders.end());

	int queries;
	scanf("%d", &queries);
	while(queries--) {
		long long limit;
		int answer = 0;
		cin >> limit;
		for(int i = 1; i <= n; i++) {
			father[i] = i;
			size[i] = 1;
		}
		for(int i = n - 1, j = n - 1; i >= 0; i--) {
			int x = orders[i].second;
			for(int k = 0; k < (int)e[x].size(); k++) {
				int y = e[x][k].first;
				if (farest[y] > farest[x] || farest[x] == farest[y] && i == 0) {
					father[y] = x;
					size[x] += size[y];
					size[y] = 0;
				}
			}
			while(farest[orders[j].second] > farest[x] + limit) {
				int t = orders[j].second;
				t = find(t);
				size[t]--;
				j--;
			}
			answer = max(answer, size[x]);
		}
		cout << answer << endl;
	}
	return 0;
}