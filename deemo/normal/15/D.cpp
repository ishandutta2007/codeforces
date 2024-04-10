#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e3 + 5;

ll n, m, x, y, val[MAXN][MAXN], p[MAXN][MAXN], mn[MAXN][MAXN], mn2[MAXN][MAXN];
vector<pair<pair<ll, ll>, ll>>	ans;
pair<ll, ll>	q[MAXN];
ll sz;
pair<ll, pair<ll, ll>>	sec[MAXN * MAXN];
bool mark[MAXN][MAXN];

int main(){
	scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			scanf("%lld", &val[i][j]);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + val[i][j];

	for (ll i = 0; i < n; i++){
		ll h = 0, t = 0;
		for (ll j = m - 1; ~j; j--){
			while (t-h && q[t - 1].S >= val[i][j])	t--;
			q[t++] = {j, val[i][j]};
			if (q[h].F >= j+y)	h++;
			mn[i][j] = q[h].S;
		}
	}
	for (ll j = 0; j < m; j++){
		ll h = 0, t = 0;
		for (ll i = n-1; ~i; i--){
			while (t-h && q[t - 1].S >= mn[i][j])	t--;
			q[t++] = {i, mn[i][j]};
			if (q[h].F >= i+x)	h++;
			mn2[i][j] = q[h].S;
		}
	}
	for (ll i = 0; i + x <= n; i++)
		for (ll j = 0; j + y <= m; j++)
			sec[sz++] = {p[i + x][j + y] - p[i][j + y] - p[i + x][j] + p[i][j] - mn2[i][j] * x * y, {i, j}};
	sort(sec, sec + sz);
	for (ll i = 0; i < sz; i++){
		ll a = sec[i].S.F, b = sec[i].S.S;
		if (!mark[a][b]){
			ans.push_back({{a, b}, sec[i].F});
			for (ll c = max(0ll, a-x+1); c < min(a+x, n); c++)
				for (ll d = max(0ll, b-y+1); d<min(b+y, m); d++)
					mark[c][d] = 1;
		}
	}
	
	printf("%lld\n", (ll)ans.size());
	for (auto z:ans)
		printf("%lld %lld %lld\n", z.F.F+1, z.F.S+1, z.S);
	return 0;
}