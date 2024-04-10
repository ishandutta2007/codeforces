#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
bool spec[MN];
int d1[MN];
int dn[MN];
vector<int> adj[MN];
void bfs (int st, int dist[MN]) {
	queue<int> q;
	q.push(st); dist[st] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i : adj[cur]) if (dist[cur] + 1 < dist[i]) {
			dist[i] = dist[cur] + 1;
			q.push(i);
		}
	}
}
int main() {
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	vector<int> special;
	while (k--) {
		int a; scanf ("%d",&a); special.push_back(a); spec[a] = 1;
	}
	while(m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(d1,0x3f,sizeof d1); memset(dn,0x3f,sizeof dn);
	bfs(1,d1);
	bfs(n,dn);
	sort(all(special),[&](int a, int b) {return d1[a] < d1[b];});
	vector<int> suf(special.size());
	for (int i = (int)special.size()-1; i >= 0; i--) {
		suf[i] = max((i+1==special.size() ? 0 : suf[i+1]),dn[special[i]]);
	}
	int ret = 0;
	for (int i = 0; i+1 < special.size(); i++) {
		int cur = special[i];
		ret = max(ret,d1[cur]+suf[i+1]+1);
	}
	printf ("%d\n",min(ret,d1[n]));
    return 0;
}