#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int N;
unordered_set<int> P[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int n = 1; n <= N; ++n) {
		P[n] = P[n - 1];
		char k = '\0';
		int p;
		while(k != '+' && k != '-') cin >> k;
		cin >> p;
		if(k == '+') {
			P[n].insert(p);
		} else {
			if(P[n].find(p) == P[n].end()) {
				for(int m = 0; m < n; ++m)
					P[m].insert(p);
			} else {
				P[n].erase(p);
			}
		}
	}
	
	int ans = 0;
	for(int n = 0; n <= N; ++n)
		ans = max(ans, int(P[n].size()));
	
	cout << ans;
}