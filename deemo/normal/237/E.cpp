#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 3e2 + 3;
const int MAXE = 1e4 + 3;

int ans, nd[30], x[30];
int from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], cost[2 * MAXE], prv[2 * MAXE], head[MAXN], ec;
int q[MAXN * MAXE];
int d[MAXN], par[MAXN];
bool mark[MAXN];

void add_edge(int u, int v, int uv, int cc = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, cost[ec] = cc, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = 0, cost[ec] = -cc, prv[ec] = head[v];	head[v] = ec++;
}

int spfa(int source, int sink){
	fill(d, d + MAXN, INT_MAX);
	memset(mark, 0, sizeof(mark));
	memset(par, -1, sizeof(par));
	int h = 0, t = 0;
	q[t++] = source;	d[source] = 0, mark[source] = 1;
	while (h < t){
		int v = q[h++];	mark[v] = 0;
		for (int e = head[v]; e != -1; e = prv[e])
			if (cap[e] && d[v] + cost[e] < d[to[e]]){
				d[to[e]] = d[v] + cost[e];
				par[to[e]] = e;
				if (!mark[to[e]])
					mark[to[e]] = 1, q[t++] = to[e];
			}
	}

	if (d[sink] == INT_MAX)	return	0;
	int v = sink, e = par[sink];
	while (e != -1){
		ans += cost[e];
		cap[e]--, cap[e^1]++;

		v = from[e];
		e = par[v];
	}
	return	1;
}

int go(int source, int sink){
	int ret = 0, x;
	while ((x = spfa(source, sink)))	ret += x;
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string temp;	cin >> temp;	int sm = temp.size();
	for (char ch:temp)	nd[ch - 'a']++;

	memset(head, -1, sizeof(head));
	int n;	cin >> n;
	int source = 0, sink = n + 26 + 1;
	for (int i = 0; i < n; i++){
		string s; int cc;	cin >> s >> cc;
		add_edge(source, i + 1, cc);

		memset(x, 0, sizeof(x));
		for (char ch:s)	x[ch - 'a']++;
		for (int j = 0; j < 26; j++)
			add_edge(i + 1, n + j + 1, x[j], i + 1);
	}
	for (int j = 0; j < 26; j++)
		add_edge(n + j + 1, sink, nd[j]);
	
	if (go(source, sink) == sm)
		cout << ans << "\n";
	else
		cout << "-1\n";
	return	0;
}