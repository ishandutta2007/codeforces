#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN], x, y, sec[MAXN];
ll pt[2][MAXN];

bool cmp(int u, int v){return a[u] - b[u] > a[v] - b[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y;
	y = min(y, n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < n; i++)
		pt[0][i+1] = pt[0][i] + max(a[sec[i]], b[sec[i]]);
	for (int i = 0; i < n; i++)
		pt[1][i+1] = pt[1][i] + b[sec[i]];

	ll ans = pt[0][y] + (pt[1][n] - pt[1][y]);
	if (y){
		y--;
		for (int i = 0; i < n; i++){
			int id = sec[i];

			ll ret = 1ll*a[id]*(1<<x);
			if (i >= y)
				ret += pt[0][y] + (pt[1][i] - pt[1][y]) + (pt[1][n] - pt[1][i+1]);
			else
				ret += pt[0][i] + (pt[0][min(n, y+1)] - pt[0][i+1]) + (pt[1][n] - pt[1][min(n, y+1)]);
			ans = max(ans, ret);
		}
	}
	cout << ans << "\n";
	return 0;
}