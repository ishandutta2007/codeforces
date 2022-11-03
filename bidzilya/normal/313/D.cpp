#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

const int MAX_INT = (1 << 31)-1;
const ll MAX_LL = (1LL << 63)-1;

int n,m,k;
vector<vector<int> > cost;
vector<vector<ll> > a;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m >> k;
	cost.resize(n+1);
	for (int i=0; i<=n; ++i)
		cost[i].assign(n+1, MAX_INT);
	for (int i=0; i<m; ++i)
	{
		int l,r,x;
		cin >> l >> r >> x;
		for (int j=l; j<=r; ++j)
			cost[j][r] = min(cost[j][r], x);
	}
	a.resize(n+1);
	for (int i=0; i<=n; ++i)
		a[i].resize(n+1, MAX_LL);
	a[0][0] = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<=n; ++j)
			if (a[i][j] != MAX_LL)
			{
				a[i+1][j] = min(a[i+1][j], a[i][j]);
				for (int t=i+1; t<=n; ++t)
					if (cost[i+1][t] != MAX_INT)
						a[t][j+t-i] = min(a[t][j+t-i], a[i][j]+cost[i+1][t]);
			}
	ll ans = -1;
	for (int i=k; i<=n; ++i)
		if (a[n][i]!=MAX_LL && (ans == -1 || a[n][i]<ans))
			ans = a[n][i];
	cout << ans << endl;
	return 0;
}