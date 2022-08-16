#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int a[105][105];

int main() {
	fast_cin();
	int n, m; cin >> m >> n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin >> a[i][j];

	vector<int> RES(n);
	iota(RES.begin(), RES.end(), 1);

	for(int cand = 1; cand < m; ++cand){
		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 1);
		sort(ind.begin(), ind.end(),[&](int i, int j){
			return a[i][cand] - a[i][m] > a[j][cand] - a[j][m];
		});

		int delta = 0;
		vector<int> now;
		for(auto i:ind){
			if(delta + a[i][cand] - a[i][m] >= 0)
				delta += a[i][cand] - a[i][m];
			else
				now.push_back(i);
		}

		if(now.size() < RES.size())
			RES = now;
	}
	cout << RES.size() << '\n';
	for(auto i:RES) cout << i << ' '; cout << '\n';
}