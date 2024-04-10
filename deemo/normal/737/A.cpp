#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int INF = 2e9 + 7;

int n, m, s, t, g[MAXN];
pair<int, int>	vec[MAXN];

int get(int f){
	int ret = 0;
 	for (int i = 0; ret < INF && i + 1 < m; i++){
		int dis = g[i + 1] - g[i];
		if (dis > f)	return INF;
		ret += dis<<1;
		int z = min(dis, f - dis);
		ret -= z;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < n; i++)
		cin >> vec[i].F >> vec[i].S;
	for (int i = 0; i < m; i++)
		cin >> g[i];
	g[m++] = 0;
	g[m++] = s;
	sort(g, g + m);

	int b = 1, e = 1e9, ret = 2e9;
	while (b <= e){
		int mid = b + e >> 1, mx = 0;
		for (int i = 0; i < n; i++)
			if (vec[i].F <= mid)
				mx = max(mx, vec[i].S);
		if (get(mx) <= t)
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	if (ret > 1e9 + 7)
		ret = -1;
	cout << ret << "\n";
	return 0;
}