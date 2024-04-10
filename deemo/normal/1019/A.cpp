#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e3 + 10;
const ll INF = 1e18;

int n, m, a[MAXN], b[MAXN], sec[MAXN];
vector<int> vec[MAXN];

bool cmp(int u, int v){return b[u] < b[v];}

ll get(int t){
	int rem = t - (int)vec[0].size();
	ll ret = 0;
	int sz = 0;
	for (int i = 1; i < m; i++){
		int pt = vec[i].size();
		while (pt >= t){
			ret += vec[i][--pt];
			rem--;
		}
		while (pt)
			sec[sz++] = vec[i][--pt];
	}
	if (rem < 0) return INF;

	sort(sec, sec + sz);
	for (int i = 0; i < rem; i++) ret += sec[i];

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i], a[i]--, vec[a[i]].push_back(b[i]);

	for (int i = 0; i < m; i++){
		sort(vec[i].begin(), vec[i].end());
		reverse(vec[i].begin(), vec[i].end());
	}

	ll ans = 1e18;
	for (int i = max(1, (int)vec[0].size()); i <= n; i++)
		ans = min(ans, get(i));
	cout << ans << "\n";
	return 0;
}