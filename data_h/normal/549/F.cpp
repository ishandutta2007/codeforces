#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3e5 + 7;

int n, k;
int s[N], size[N], val[N];
vector<pair<int, int> > events;
map<int, int> f[N];
bool exist[N];
int father[N];

int find(int x) {
	int p = x;
	while (father[p] != p) {
		p = father[p];
	}
	while (x != p) {
		int t = father[x];
		father[x] = p;
		x = t;
	}
	return p;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		val[i] = x % k;
		s[i] = (s[i - 1] + x) % k;
		events.push_back(make_pair(x, i));
		exist[i] = false;
	}

	for (int i = 1; i <= n; i++) {
		father[i] = i;
		f[i][s[i]]++;
		size[i] = 1;
	}

	long long answer = 0;
	sort(events.begin(), events.end());
	for (int i = 0; i < n; i++) {
		int pos = events[i].second;
		int lp, rp;
		if (exist[pos - 1]) {
			lp = find(pos - 1);
			answer += f[lp][s[pos - 1]];
			answer--;
			answer += (s[pos - size[lp] - 1] == s[pos - 1]);
		}
		if (exist[pos + 1]) {
			rp = find(pos + 1);
			answer += f[rp][s[pos]];
		}
		if (exist[pos - 1] && exist[pos + 1]) {
			if (f[lp].size() < f[rp].size()) {
				for (map<int, int> :: iterator it = f[lp].begin(); it != f[lp].end(); ++it) {
					int v = (val[pos] + it->first) % k;
					if (f[rp].count(v)) {
						answer += 1LL * it->second * f[rp][v]; 
					}
				}
			} else {
				for (map<int, int> :: iterator it = f[rp].begin(); it != f[rp].end(); ++it) {
					int v = (it->first - val[pos] + k) % k;
					if (f[lp].count(v)) {
						answer += 1LL * it->second * f[lp][v];
					}
				}
			}

			int v = (val[pos] + s[pos - 1]) % k;
			if (f[rp].count(v)) {
				answer -= f[rp][v];
			}
			v = (val[pos] + s[pos - size[lp] - 1]) % k;
			if (f[rp].count(v)) {
				answer += f[rp][v];
			}

			// combine
			if (f[lp].size() > f[rp].size()) {
				swap(lp, rp);
			}
			father[lp] = rp;
			size[rp] += size[lp] + 1;
			for (map<int, int> :: iterator it = f[lp].begin(); it != f[lp].end(); ++it) {
				f[rp][it->first] += it->second;
			}
			f[rp][s[pos]]++;
		} else if (exist[pos - 1]) {
			father[pos] = lp;
			size[lp]++;
			f[lp][s[pos]]++;
		} else if (exist[pos + 1]) {
			father[pos] = rp;
			size[rp]++;
			f[rp][s[pos]]++;
		}
		exist[pos] = 1;
		//cout << answer << endl;
	}
	cout << answer << endl;
}