#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 25;
const int max_v = 4 * max_n * max_n;
const long long inf = 1111111111111LL;

class MaximumFlow {
	int s, f;
public:
	struct edge {
		int u, v;
		int capacity, flow;
		edge() { u = v = capacity = flow = 0;}
		edge(int u_, int v_, int capacity_, int flow_) :
		  u(u_), v(v_), capacity(capacity_), flow(flow_) {}
	};

	vector <edge> edges;
	vector <vector <int> > graph;
	vector <int> ptr, level;
	queue <int> q;
	int n;

	MaximumFlow() {}

	MaximumFlow(int number) {
		n = number;
		graph.resize(n);
		ptr.assign(n, 0);
		level.resize(n);
	}

	void add_edge(int u, int v, int capacity) {
		int sz = (int)(edges.size());
		edges.push_back(edge(u, v, capacity, 0));
		edges.push_back(edge(v, u, 0, 0));
		graph[u].push_back(sz);
		graph[v].push_back(sz + 1);
	}

	void updateLevels() {
		level.assign(n, -1);
		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int topq = q.front();
			q.pop();
			for (int index = 0; index < graph[topq].size(); ++index) {
				int i = graph[topq][index];
				int to = edges[i].v;
				if (edges[i].capacity - edges[i].flow == 0) {
					continue;
				}
				if (level[to] == -1) {
					level[to] = level[topq] + 1;
					q.push(to);
				}
			}
		}
	}

	int pushFlow(int v, int flow) {
		if (v == f || flow == 0) {
			return flow;
		}
		for (; ptr[v] < graph[v].size(); ++ptr[v]) {
			int index = graph[v][ptr[v]];
			int to = edges[index].v;
			if (level[v] + 1 == level[to]) {
				int pushed = pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
				if (pushed > 0) {
					edges[index].flow += pushed;
					edges[index ^ 1].flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	int dinicFlow(int start, int finish) {
		s = start, f = finish;
		int result = 0;
		while (true) {
			updateLevels();
			if (level[f] == -1) {
				break;
			}
			while (true) {
				int pushed = pushFlow(start, 1);
				if (pushed == 0) {
					break;
				}
				result += pushed;
			}
			ptr.assign(n, 0);
		}
		return result;
	}
};

struct edge {
    int v, c, f, numr;
    edge() {
    }
    edge(int v, int c, int f, int numr) : v(v), c(c), f(f), numr(numr) {
    }
};

int last_res, n, m, k, k1, k2, x[2][max_v], y[2][max_v], t[2][max_v], used[max_v];
long long last, dist[max_v][max_n][max_n];
string s[max_n];
vector<long long> v;
MaximumFlow F;

bool check(long long x) {
    //cout << x << " " << last << endl;
    int s = 2 * n * m + 2 * k;
    int t = s + 1;
    if (x <= last) {
        F = MaximumFlow(2 * n * m + 2 * k + 5);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int num = 2 * (i * m + j);
                F.add_edge(num, num + 1, 1);
            }
        }
        //cout << endl;
        for (int i = 0; i < k; ++i) {
            F.add_edge(s, 2 * n * m + i, 1);
            F.add_edge(2 * n * m + k + i, t, 1);
        }
        //cout << endl;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int w = 0; w < m; ++w) {
                    int num = 2 * (j * m + w);
                    if (dist[i][j][w] > -1 && x >= dist[i][j][w]) {
                        F.add_edge(2 * n * m + i, num, 1);
                    }
                }
            }
        }
        //cout << endl;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int w = 0; w < m; ++w) {
                    int num = 2 * (j * m + w) + 1;
                    if (dist[i + k][j][w] > -1 && x >= dist[i + k][j][w]) {
                        F.add_edge(num, 2 * n * m + k + i, 1);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int w = 0; w < m; ++w) {
                    int num = 2 * (j * m + w);
                    if (dist[i][j][w] > -1 && x >= dist[i][j][w] && last < dist[i][j][w]) {
                        F.add_edge(2 * n * m + i, num, 1);
                    }
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int w = 0; w < m; ++w) {
                    int num = 2 * (j * m + w) + 1;
                    if (dist[i + k][j][w] > -1 && x >= dist[i + k][j][w] && last < dist[i + k][j][w]) {
                        F.add_edge(num, 2 * n * m + k + i, 1);
                    }
                }
            }
        }
    }
    //cout << endl;
    memset(used, 0, sizeof(used));
    int res = 0;
    if (x > last) {
        res = last_res;
    }
    res += F.dinicFlow(s, t);
    last = x;
    last_res = res;
    return res == k;
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int num, int poz) {
    int stx = x[num][poz - num * k];
    int sty = y[num][poz - num * k];
    int tt = t[num][poz - num * k];
    dist[poz][stx][sty] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(stx, sty));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        v.push_back(dist[poz][x][y]);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny) && s[nx][ny] == '.' && dist[poz][nx][ny] == -1) {
                dist[poz][nx][ny] = dist[poz][x][y] + tt;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k1 >> k2;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int st1 = 0, st2 = 0;
    if (k1 + 1 == k2) {
        k = k2;
        cin >> x[0][0] >> y[0][0] >> t[0][0];
        st1 = 1;
    } else if (k2 + 1 == k1) {
        k = k1;
        cin >> x[1][0] >> y[1][0] >> t[1][0];
        st2 = 1;
    } else {
        cout << -1 << endl;
        return 0;
    }
    for (int i = st1; i < k; ++i) {
        cin >> x[0][i] >> y[0][i] >> t[0][i];
    }
    for (int i = st2; i < k; ++i) {
        cin >> x[1][i] >> y[1][i] >> t[1][i];
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < k; ++i) {
        --x[0][i];
        --x[1][i];
        --y[0][i];
        --y[1][i];
        bfs(0, i);
        bfs(1, k + i);
    }
    sort(v.begin(), v.end());
    last = inf + 1;
    if (!check(inf)) {
        cout << -1 << endl;
        return 0;
    }
    long long l = -1, r = v.size() - 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(v[mid])) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << v[r] << endl;
    return 0;
}