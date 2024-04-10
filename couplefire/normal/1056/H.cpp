//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 300000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;
const int SQ = 550;


vi H, a[N];
vector<pii> koj[N];
int ind[N / SQ + 10][N], cnt, nxt[N];
int n, q, t, tt, nn;

int Main(){
	H.clear();
	scanf("%d %d", &n, &q);
	cnt = 0;
	for (int i = 1; i <= q; i++){
		a[i].clear();
		a[i].shrink_to_fit();
		int k;
		scanf("%d", &k);
		if (k >= N / SQ){
			H.pb(i), cnt++;
		}
		for (int j = 0; j < k; j++){
			int x;
			scanf("%d", &x);
			a[i].pb(x);
			if (k >= SQ) ind[cnt][x] = j;
			else koj[x].pb({i, j});
		}
	}
	bool ans = 1;
	for (int i = 1; i <= q; i++)for (int j = 1; j <= cnt; j++){
		int mx = -1;
		for (int k = a[i].size() - 1; k >= 0; k--){
			int u = a[i][k];
			if (ind[j][u] == -1) continue;
			if (ind[j][u] <= mx) if (a[H[j - 1]][ind[j][u] + 1] != a[i][k + 1]) ans = 0;
			mx = max(mx, ind[j][u]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (auto u:koj[i]){
			for (int k = u.S + 1; k < a[u.F].size(); k++){
				if (nxt[a[u.F][k]]  == 0)nxt[a[u.F][k]]  = a[u.F][u.S + 1];
				else if(nxt[a[u.F][k]] != a[u.F][u.S + 1]) ans = 0;
			}
		}
		for (auto u:koj[i]){
			for (int k = u.S + 1; k < a[u.F].size(); k++){
				nxt[a[u.F][k]] = 0;
			}
		}		
		koj[i].clear();
	}
	for (int i = 0; i < H.size(); i++){
		for (auto u:a[H[i]]) ind[i + 1][u] = -1;
	}
	if (ans == 0) printf("Human\n");
	else printf("Robot\n");
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d", &t);
	memset(ind, -1, sizeof ind);
	while (t--) Main();
	return 0;
}