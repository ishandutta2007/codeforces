#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int n, m, p[MAXN], pos[MAXN];
vector<int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--, pos[p[i]] = i;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	ll ans = 0;
	int l = 0;
	for (int i = 0; i < n; i++){
		for (int u:vec[p[i]])
			if (pos[u] < i)	l = max(l, pos[u] + 1);
		ans += (i + 1) - l;
	}
	cout << ans << "\n";
	return	0;
}