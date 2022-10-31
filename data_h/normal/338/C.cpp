#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long a[20], b[20];
vector<pair<long long, int> > p[20]; 
int n;

int ans = int(1e9);

int fat[20];

void dfs(int dep) {
	if (dep > n) {
		if (fat[1] == 3 && fat[2] == n + 1 && fat[3] == 4 && fat[4] == n + 1)
			fat[1] = 3;
		int now = 0;
		static vector<int> vec[12];
		
		for(int i = 1; i <= n + 1; i++)
			vec[i].clear();
		for(int i = 1; i <= n; i++)
			vec[fat[i]].push_back(i);
		for(int i = n + 1; i >= 1; i--) {
			now++;
			if (i == n + 1) {
				if (vec[i].size() == 1)
					now--;
				continue;
			}
			if (p[i].size() == 1 && p[i][0].second == 1)
				continue;
			for(int j = 0; j < p[i].size(); j++) {
				long long val = p[i][j].first;
				int cnt = 0;
				for(int k = 0; k < vec[i].size(); k++) {
					int div = vec[i][k];
					for(int l = 0; l < p[div].size(); l++)
						if (p[div][l].first == val)
							cnt += p[div][l].second;
				}
				now += p[i][j].second - cnt;
			}
		}
		ans = min(ans, now);
		return ;
	}
	for(int i = dep + 1; i <= n; i++)
		if (b[i] % a[dep] == 0) {
			b[i] /= a[dep];
			fat[dep] = i;
			dfs(dep + 1);
			b[i] *= a[dep];
		}
	fat[dep] = n + 1;
	dfs(dep + 1);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		b[i] = a[i];
	for(int i = 1; i <= n; i++) {
		long long b = a[i];
		for(long long j = 2; j * j <= b; j++) {
			if (b % j == 0) {
				pair<long, long> tmp(j, 0);
				while(b % j == 0)
					tmp.second++, b /= j;
				p[i].push_back(tmp);
			}
		}
		if (b > 1)
			p[i].push_back(make_pair(b, 1));
		sort(p[i].begin(), p[i].end());
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}