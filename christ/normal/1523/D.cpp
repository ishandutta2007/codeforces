#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
bool likes[MN][60];
int main () {
	int n,m,p; scanf ("%d %d %d",&n,&m,&p);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			char ch; scanf (" %c",&ch);
			likes[i][j] = ch == '1';
		}
	}
	int ret = 0; vector<int> to_print;
	mt19937 rnd(time(NULL));
	for (int ITER = 0; ITER < 50; ITER++) {
		int x = uniform_int_distribution<int>(1,n)(rnd);
		vector<int> want;
		for (int i = 0; i < 60; i++) if (likes[x][i]) want.push_back(i);
		vector<int> dp(1 << (int)want.size());
		for (int i = 1; i <= n; i++) {
			int go = 0;
			for (int j = 0; j < (int)want.size(); j++) if (likes[i][want[j]]) go |= (1 << j);
			dp[((1 << (int)want.size()) - 1) ^ go]++;
		}
		for (int i = 0; i < (int)want.size(); i++) {
			for (int mask = 0; mask < (int)dp.size(); mask++) if (mask >> i & 1) {
				dp[mask] += dp[mask ^ (1 << i)];
			}
		}
		for (int mask = 0; mask < (int)dp.size(); mask++) if (dp[mask] >= (n + 1) / 2) {
			int att = (int)want.size() - __builtin_popcount(mask);
			if (att > ret) {
				ret = att;
				to_print.clear();
				for (int i = 0; i < (int)want.size(); i++) if (!(mask >> i & 1)) to_print.push_back(want[i]);
			}
		}
	}
	vector<char> gg(m,'0');
	for (int i : to_print) gg[i] = '1';
	for (char c : gg) printf ("%c",c);
	printf ("\n");
	return 0;
}