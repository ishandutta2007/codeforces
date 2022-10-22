#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e3 + 10;

int n, lim, a[MAXN], b[MAXN], sub[MAXN];
ll d[MAXN][2][MAXN], sec[MAXN], gec[MAXN];
vector<int> adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> lim;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i]; b[i] = a[i] - b[i];
		int p;
		if (i){
			cin >> p, p--;
			adj[p].push_back(i);
		}
	}

	memset(d, 63, sizeof(d));
	for (int v = n-1; ~v; v--){
		sub[v] = 1;
		d[v][0][0] = 0;
		d[v][0][1] = a[v];
		for (int u:adj[v]){
			memset(sec, 63, sizeof(sec));
			for (int j = 0; j <= sub[v]; j++) sec[j] = d[v][0][j];
			
			for (int i = 0; i <= sub[v]; i++)
				for (int j = 0; j <= sub[u]; j++)
					sec[i+j] = min(sec[i+j], d[v][0][i] + d[u][0][j]);
			
			sub[v] += sub[u];
			for (int i = 0; i <= sub[v]; i++)
				d[v][0][i] = sec[i];
		}

		sub[v] = 1;
		d[v][1][0] = 0;
		for (int u:adj[v]){
			memset(sec, 63, sizeof(sec));
			for (int j = 0; j <= sub[v]; j++) sec[j] = d[v][1][j];
			
			for (int i = 0; i <= sub[v]; i++)
				for (int j = 0; j <= sub[u]; j++)
					sec[i+j] = min(sec[i+j], d[v][1][i] + d[u][0][j]);
			
			sub[v] += sub[u];
			for (int i = 0; i <= sub[v]; i++)
				d[v][1][i] = sec[i];
		}
		memset(gec, 63, sizeof(gec));
		for (int i = 0; i <= sub[v]; i++){
			gec[i] = d[v][1][i];
			d[v][1][i] = 1e18;
		}
		
		sub[v] = 1;
		d[v][1][1] = b[v];
		for (int u:adj[v]){
			memset(sec, 63, sizeof(sec));
			for (int j = 0; j <= sub[v]; j++) sec[j] = d[v][1][j];
			
			for (int i = 0; i <= sub[v]; i++)
				for (int j = 0; j <= sub[u]; j++)
					sec[i+j] = min(sec[i+j], d[v][1][i] + d[u][1][j]);
			
			sub[v] += sub[u];
			for (int i = 0; i <= sub[v]; i++)
				d[v][1][i] = sec[i];
		}
		for (int i = 0; i <= sub[v]; i++)
			d[v][1][i] = min(d[v][1][i], gec[i]);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (min(d[0][0][i], d[0][1][i]) <= lim)
			ans = i;
	cout << ans << "\n";
	return 0;
}