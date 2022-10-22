#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e3 + 10;

int n, m;
vector<int>	adj[MAXN];
int q[MAXN], d[MAXN], sec[MAXN];
priority_queue<pair<int, int>>	pq;
vector<pair<int, int>>	vec[MAXN];

bool cmp(int u, int v){return d[u] < d[v];}

int get(int v, int nd, int tot){
	int ret = n+3;
	{
		memset(d, 63, sizeof(d));
		d[v] = 0;
		int h = 0, t = 0;
		q[t++] = v;
		while (h < t){
			int u = q[h++];
			for (int z:adj[u])
				if (d[z] > d[u] + 1){
					d[z] = d[u] + 1;
					q[t++] = z;
				}
		}
		iota(sec, sec + n, 0);
		sort(sec, sec + n, cmp);
	}

	while (pq.size())
		pq.pop();
	ll cost = 0;
	int cur = 0;
	for (int i = 0; i < n;){
		if (d[sec[i]] > 1e7)	break;
		int j = i;
		while (j < n && d[sec[i]] == d[sec[j]]){
			for (auto u:vec[sec[j]])
				pq.push(u), cur += u.S, cost += 1ll * u.S * u.F;
			while (cur > nd){
				auto u = pq.top();	pq.pop();
				int g = min(cur - nd, u.S);
				cur -= g;
				u.S -= g;
				cost -= 1ll * g * u.F;
				if (u.S)	pq.push(u);
			}
			j++;
		}

		if (cur == nd && cost <= tot)
			ret = min(ret, d[sec[i]]);
		i = j;
	}
	if (ret > n)	ret = -1;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll tot = 0;
	{
		int t;	cin >> t;
		while (t--){
			int a, b, c;	cin >> a >> b >> c;	a--;
			vec[a].push_back({c, b});
			tot += b;
		}
	}

	int q;	cin >> q;
	while (q--){
		int a, b, c;	cin >> a >> b >> c, a--;
		cout << get(a, b, c) << "\n";
	}	
	return 0;
}