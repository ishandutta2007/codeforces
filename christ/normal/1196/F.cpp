#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
struct Edge {
	int a,b,w;
	void read() {scanf ("%d %d %d",&a,&b,&w);}
	bool operator< (const Edge &o) const {
		return w < o.w;
	}
};
vector<int> nodes;
int getx (int x) {
	return lower_bound(all(nodes),x)-nodes.begin();
}
ll dist[1000][1000];
int main() {
    int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	vector<Edge> edges(m);
	for (auto &au : edges) au.read();
	sort(all(edges));
	while (edges.size() > 400) edges.pop_back();
	for (Edge &e : edges) nodes.push_back(e.a), nodes.push_back(e.b);
	sort(all(nodes));
	nodes.erase(unique(all(nodes)),nodes.end());
	memset(dist,0x3f,sizeof dist);
	for (int i = 0; i < nodes.size(); i++) dist[i][i] = 0;
	for (Edge &e : edges) {
		int a = getx(e.a); int b = getx(e.b);
		dist[a][b] = dist[b][a] = min(dist[a][b],(ll)e.w);
	}
	int sz = nodes.size();
	for (int k = 0; k < sz; k++)
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
	vector<ll> dists;
	for (int i = 0; i < sz; i++)
		for (int j = i+1; j < sz; j++)
			dists.push_back(dist[i][j]);
	sort(all(dists));
	printf ("%lld\n",dists[k-1]);
    return 0;
}