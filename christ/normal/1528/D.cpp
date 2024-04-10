#include <bits/stdc++.h>
using namespace std;
const int MN = 600 + 5;
int dist[MN][MN];
bool vis[MN];
vector<array<int,2>> adj[MN];
vector<array<int,2>> fix[MN];
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b,c; scanf ("%d %d %d",&a,&b,&c);
		adj[a].push_back({b,c});
	}
	for (int st = 0; st < n; st++) {
		memset(dist[st],0x3f,sizeof dist[st]);
		memset(vis,0,sizeof vis);
		dist[st][st] = 0;
		for (;;) {
			int mn = -1;
			for (int i = 0; i < n; i++) if (!vis[i] && (mn == -1 || dist[st][i] < dist[st][mn])) mn = i;
			if (mn == -1) break;
			vis[mn] = true;
			for (int i = 0; i < n; i++) fix[i].clear();
			int MIN = (int)1.5e9;
			for (auto &[b,c] : adj[mn]) {
				int curpos = (b + dist[st][mn]) % n;
				MIN = min(MIN,c + (n - curpos) % n);
				if (curpos != 0) fix[curpos].push_back({b,c});
			}
			for (int i = 0; i < n; i++) {
				for (auto &[b,c] : fix[i]) MIN = min(MIN,c-i);
				int got = MIN + i;
				dist[st][i] = min(dist[st][i],dist[st][mn] + got);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf ("%d%c",dist[i][j]," \n"[j+1==n]);
		}
	}
	return 0;
}