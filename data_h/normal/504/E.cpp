#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define left LEFT
#define rank RANK

const int DEBUG = 0;
const int N = 333333 * 2;
const int MAGIC = 31;

char buffer[N], str[N];
int n;
vector<int> edges[N];
int top[N], pos[N], rpos[N << 1], father[N], size[N], son[N], dep[N], left[N << 1], right[N << 1];
int total;

int sa[N], ta[N], tb[N], *rank = ta, *tmp = tb;
int height[N], myLog[N], f[N][20];

bool cmp(int i, int j, int l) {
	return tmp[i] == tmp[j] && tmp[i + l] == tmp[j + l];
}

void radixSort(int n, int m) {
	static int w[N];
	fill(w, w + m, 0);
	for (int i = 0; i < n; i++) {
		w[rank[i]]++;
	}
	for (int i = 1; i < m; i++) {
		w[i] += w[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		sa[--w[rank[tmp[i]]]] = tmp[i];
	}
}

void suffixArray(int n, int m) {
	for (int i = 0; i < n; i++) {
		rank[i] = str[i];
		tmp[i] = i;
	}
	radixSort(n, m);
	for (int j = 1, i, p; j < n; j <<= 1, m = p) {
		for (i = n - j, p = 0; i < n; i++) {
			tmp[p++] = i;
		}
		for (i = 0; i < n; i++) {
			if (sa[i] >= j) {
				tmp[p++] = sa[i] - j;
			}
		}
		radixSort(n, m);
		for (swap(tmp, rank), rank[sa[0]] = 0, i = p = 1; i < n; i++) {
			rank[sa[i]] = cmp(sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
	for (int i = 0, j, k = 0; i < n; ++i, k = max(k - 1, 0)) {
		if (rank[i]) {
			j = sa[rank[i] - 1];
			for (; str[i + k] == str[j + k]; k++);
			height[rank[i]] = k;
		}
	}

	for (int i = 2; i <= n; i++) {
		myLog[i] = myLog[i >> 1] + 1;
	}
	for (int i = 1; i < n; i++) {
		f[i][0] = height[i];
	}
	for (int j = 1; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) <= n; i++) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int lcp(int l, int r) {
	if (l > r) {
		return N;
	}
	int len = myLog[r - l + 1];
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}

void dfs(int x, int fat) {
	father[x] = fat;
	size[x] = 1;
	int maxSize = -1, who = 0;
	for(int i = 0; i < (int)edges[x].size(); i++) {
		int y = edges[x][i];
		if (y != fat) {
			dfs(y, x);
			size[x] += size[y];
			if (size[y] > maxSize) {
				who = y;
				maxSize = size[y];
			}
		}
	}
	son[x] = who;
}

void go(int x, int tp) {
	++total;
	rpos[total] = x;
	pos[x] = total;
	top[x] = tp;

	if (son[x]) {
		dep[son[x]] = dep[x];
		go(son[x], tp);
	}

	for(int i = 0; i < (int)edges[x].size(); i++) {
		int y = edges[x][i];
		if (y != father[x] && y != son[x]) {
			dep[y] = dep[x] + 1;
			go(y, y);
		}
	}
}

void build() {
	dfs(1, 0);
	total = 0;
	go(1, 1);
	int ln = 0;
	for(int i = 1; i <= n; i++) {
		str[ln++] = buffer[rpos[i]];
	}
	for(int i = n; i >= 1; i--) {
		str[ln++] = buffer[rpos[i]];
	}
	str[ln++] = 0;
	suffixArray(ln, 256);
}

pair<vector<pair<int, int> >, vector<pair<int, int> > > get_sector(int a, int b) {
	vector<pair<int, int> > forward, backward;
	while(top[a] != top[b]) {
		if (dep[a] >= dep[b]) {
			forward.push_back(make_pair(pos[top[a]], pos[a]));
			a = father[top[a]];
		} else {
			backward.push_back(make_pair(pos[top[b]], pos[b]));
			b = father[top[b]];
		}
	}
	if (pos[a] < pos[b]) {
		backward.push_back(make_pair(pos[a], pos[b]));
	} else {
		forward.push_back(make_pair(pos[b], pos[a]));
	}
	reverse(backward.begin(), backward.end());
	return make_pair(forward, backward);
}

int calc(int a, int b, int c, int d) {
	if (b < a) {
		a = 2 * n - a + 1; a--;
		b = 2 * n - b + 1; b--;
	} else {
		a--;
		b--;
	}

	if (d < c) {
		c = 2 * n - c + 1; c--;
		d = 2 * n - d + 1; d--;
	} else {
		c--;
		d--;
	}

if (DEBUG) {
	for(int i = a; i <= b; i++) {
		printf("%c", str[i]);
	}
	cout << endl;

	for(int i = c; i <= d; i++) {
		printf("%c", str[i]);
	}
	cout << endl;
}
	int l = rank[a], r = rank[c];
	if (l > r) {
		swap(l, r);
	}
	int p = lcp(l + 1, r);
	return min(p, min(b - a + 1, d - c + 1));
}

void debug(vector<pair<int, int> > vec) {
	for(int i = 0; i < (int)vec.size(); i++) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", buffer + 1);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	build();
	if (DEBUG) {
		cout << "total = " << total << " " << str << endl;
	}
	//return 0;

	int queries;
	scanf("%d", &queries);
	while(queries--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		pair<vector<pair<int, int> >, vector<pair<int, int> > > first = get_sector(a, b);
		pair<vector<pair<int, int> >, vector<pair<int, int> > > second = get_sector(c, d);
		pair<int, int> posa, posb;
		int mf = first.first.size(), ms = second.first.size();
		posa = make_pair(0, mf ? first.first[0].second : first.second[0].first);
		posb = make_pair(0, ms ? second.first[0].second : second.second[0].first);
		int answer = 0;

		if (DEBUG) {
			debug(first.first);
			debug(first.second);
			cout << "*" << endl;
			debug(second.first);
			debug(second.second);
			cout << endl;
		}
		while(1) {
			int &ia = posa.first;
			pair<int, int> sa = make_pair(posa.second, ia >= mf ? first.second[ia - mf].second : first.first[ia].first);
			int &ib = posb.first;
			pair<int, int> sb = make_pair(posb.second, ib >= ms ? second.second[ib - ms].second : second.first[ib].first);
			
			int len = calc(sa.first, sa.second, sb.first, sb.second);
if (DEBUG) {
	printf("cmp %d %d %d %d\n", sa.first, sa.second, sb.first, sb.second);
}
			answer += len;
			if (len == 0) {
				break;
			}
			if (ia < mf) {
				if (posa.second - len < sa.second) {
					ia++;
					if (ia == mf + (int)first.second.size()) {
						break;
					} else {
						posa.second = (ia < mf ? first.first[ia].second : first.second[ia - mf].first);
					}
				} else {
					posa.second -= len;
				}
			} else {
				if (posa.second + len > sa.second) {
					ia++;
					if (ia == mf + (int)first.second.size()) {
						break;
					} else {
						posa.second = first.second[ia - mf].first;
					}
				} else {
					posa.second += len;
				}
			}

			if (ib < ms) {
				if (posb.second - len < sb.second) {
					ib++;
					if (ib == ms + (int)second.second.size()) {
						break;
					} else {
						posb.second = (ib < ms ? second.first[ib].second : second.second[ib - ms].first);
					}
				} else {
					posb.second -= len;
				}
			} else {
				if (posb.second + len > sb.second) {
					ib++;
					if (ib == ms + (int)second.second.size()) {
						break;
					} else {
						posb.second = second.second[ib - ms].first;
					}
				} else {
					posb.second += len;
				}
			}
		}
		if (DEBUG) {
			printf("answer = %d\n", answer);
		} else {
			printf("%d\n", answer);
		}
	}
}