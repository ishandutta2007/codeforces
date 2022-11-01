#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

vector<pair<int, int> > e[N];
int n, m;
int isTarget[N], inQueue[N];
pair<int, int> dist[N];
pair<int, int> go[N];

int main() {
	scanf("%d %d", &n, &m);
	//n = 1e5, m = 1e5 - 1;
	for (int i = 0; i < m; i++) {
		int a, b, len;
		scanf("%d %d %d", &a, &b, &len);
		//a = i; b = i + 1; len = 1;
		e[a].push_back(make_pair(b, len));
		e[b].push_back(make_pair(a, len));
	}
	
	fill(go, go + n, make_pair(-1, 0));
	fill(dist, dist + n, make_pair(INF, INF));

	{
		vector<int> queue;
		queue.push_back(n - 1);
		isTarget[n - 1] = 1;
		for (int head = 0; head < (int)queue.size(); head++) {
			int x = queue[head];
			for (int i = 0; i < (int)e[x].size(); i++) {
				int y = e[x][i].first;
				if (e[x][i].second == 0 && !isTarget[y]) {
					queue.push_back(y); 
					isTarget[y] = 1;
					go[y] = make_pair(x, 0);
				}
			}
		}
	}

	fill(inQueue, inQueue + n, 0);

	vector<int> queue;
	queue.push_back(0); 
	inQueue[0] = 1;
	dist[0] = make_pair(0, 0);
	for (int head = 0; head < (int)queue.size(); head++) {
		int x = queue[head];
		inQueue[x] = 0;
		for (int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i].first;
			pair<int, int> distance = make_pair(dist[x].first + 1, e[x][i].second);
			if (distance < dist[y]) {
				dist[y] = distance;
				if (!inQueue[y]) {
					inQueue[y] = 1;
					queue.push_back(y);
				}
			}
		}
	}

/*
	for (int i = 0; i < n; i++) {
		cout << i << " isTarget ? " << isTarget[i] << " dist = " << dist[i].first << " " << dist[i].second << endl;
	}
*/
	vector<int> active;
	{
		pair<int, int> answer = make_pair(INF, INF); 
		for (int i = 0; i < n; i++) {
			if (!isTarget[i]) {
				continue;
			}
			if (dist[i] < answer) {
				active.clear();
				answer = dist[i];
			}
			if (dist[i] == answer) {
				active.push_back(i);
			}
		}
	}


	static int visit[N];
	fill(visit, visit + n, 0);

	while (active.size() && !visit[0]) {
/*
cout << "active list " << endl;
for (int i = 0; i < (int)active.size(); i++) {
	printf("%d ", active[i]);
}
		cout << endl;
*/
		static vector<int> tmp;
		tmp.clear();
		pair<int, int> answer = make_pair(dist[active[0]].first - 1, INF);
		for (int i = 0; i < (int)active.size(); i++) {
			int x = active[i];
			for (int j = 0; j < (int)e[x].size(); j++) {
				int y = e[x][j].first;
				if (visit[y] || dist[x].second != e[x][j].second || dist[y] > answer) {
					continue;
				}
				visit[y] = 1;
				if (dist[y] < answer) {
					answer = dist[y];
					tmp.clear();
				}
				tmp.push_back(y);
			}
		}

		for (int i = 0; i < (int)active.size(); i++) {
			int x = active[i];
			for (int j = 0; j < (int)e[x].size(); j++) {
				int y = e[x][j].first;
				if (dist[x].second != e[x][j].second || dist[y] != answer) {
					continue;
				}
				go[y] = make_pair(x, e[x][j].second);
			}
		}
		swap(active, tmp);
	}

	vector<int> path;
	static string number = "";
	{
		int x = 0;
		while (x != -1) {
			//cout << x << endl;
			path.push_back(x);
			if (!isTarget[x]) {
				number += go[x].second + '0';
			}
			x = go[x].first;
		}
	}
	reverse(number.begin(), number.end());
	if (number.size() == 0) {
		number = "0";
	}
	puts(number.c_str());
	printf("%lu\n", path.size());
	for (int i = 0; i < (int)path.size(); i++) {
		int x = path[i];
		printf("%d%c", x, i == (int)path.size() - 1 ? '\n' : ' ');
	}
	return 0;
}