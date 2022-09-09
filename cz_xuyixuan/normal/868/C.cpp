#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
bool mark[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int m = (1 << k) - 1;
	bool solved = false;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j <= k; j++) {
			int t;
			cin >> t;
			now = now * 2 + t;
		}
		mark[now]= true;
		if (now == 0) solved = true;
		int t = m ^ now;
		for (int j = t; j; j = (j - 1) & t)
			if (mark[j]) solved = true;
	}
	if (solved) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}