#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
int a[N];
vector<int> era[N];
vector<int> vec;
set<int> S;
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], vec.push_back(a[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= n; i++) S.insert(i);
	for (int i = 1; i <= n; i++) {
		a[i] = upper_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		era[a[i]].push_back(i);
	}
	for (int i = 1; i < vec.size(); i++) {
		int cur = 0;
		for (int j = 0; j < era[i].size(); j++) {
			int x = era[i][j];
			cur ^= 1;
			if (j + 1 == era[i].size() || (S.upper_bound(x) == S.end() || *S.upper_bound(x) != era[i][j + 1])) {
				if (cur) return puts("NO"), 0;
			}
		}
		for (int j = 0; j < era[i].size(); j++) S.erase(era[i][j]);
	}
	return puts("YES"), 0;
}