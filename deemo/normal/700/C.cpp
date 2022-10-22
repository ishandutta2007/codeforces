#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 30;
const int MAXE = 4e4 + 10;

int n, m;
int from[MAXE * 2], to[MAXE * 2], prv[MAXE * 2], head[MAXN], ec;
int ptr[MAXN];
ll cap[MAXE * 2];

void add_edge(int u, int v, ll uv, ll vu)
{
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u]; head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v]; head[v] = ec++;
}

int d[MAXN], q[MAXN];

bool bfs(int source, int sink)
{
	memset(d, 63, sizeof(d));
	d[source] = 0;
	int h = 0, t = 0;
	q[t++] = source;
	while (h < t)
	{
		int v = q[h++];
		for (int i = head[v]; ~i; i = prv[i])
			if (cap[i] && d[to[i]] > d[v] + 1)
			{
				d[to[i]] = d[v] + 1;
				q[t++] = to[i];
			}
	}
	return (d[sink] < 1e9);
}

long long dfs(int v, int sink, long long flow = 1e18)
{
	if (v == sink || flow == 0)
		return flow;
	ll ans = 0;
	for (; ptr[v] != -1; ptr[v] = prv[ptr[v]])
		if (d[v] + 1 == d[to[ptr[v]]])
		{
			ll x = dfs(to[ptr[v]], sink, min(flow, cap[ptr[v]]));
			cap[ptr[v]] -= x;
			cap[ptr[v] ^ 1] += x;
			ans += x;
			flow -= x;
			if (flow == 0)
				break;
		}
	return ans;
}

void reset(){
	for (int i = 0; i < ec; i += 2)
		cap[i] = cap[i^1] = cap[i]+cap[i^1]>>1;
}

ll max_flow(int source, int sink){
	reset();
	ll ans = 0;
	while (bfs(source, sink))
	{
		memcpy(ptr, head, sizeof(head));
		ans += dfs(source, sink);
	}
	return ans;
}

bool vis[MAXN];
void go(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int e = head[v]; ~e; e = prv[e])
		if (cap[e])
			go(to[e]);
}

vector<int>	get(int source){
	vector<int>	vec;
	memset(vis, 0, sizeof(vis));
	go(source);
	for (int i = 0; i < ec; i += 2)
		if (vis[from[i]] ^ vis[to[i]])
			vec.push_back(i>>1);
	return vec;
}

int depth[MAXN];
bool ced[3 * MAXE];
int ff(int v, int p = -1, int de = 0){
	depth[v] = de;
	vis[v] = 1;
	int ret = de;

	for (int e = head[v]; ~e; e = prv[e])
		if (e != p){
			int u = to[e];
			if (vis[u])
				ret = min(ret, depth[u]);
			else{
				int x = ff(u, e^1, de + 1);
				if (x > de)
					ced[e] = 1;
				//cout << v << " " << x << endl;
			//	cout << x << " " << v << "    " << u << endl;
				ret = min(ret, x);
			}
		}
//	cout << v << "  " << de << " " << ret << endl;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n >> m;

	int source, sink;	
	cin >> source >> sink, source--, sink--;

	const ll INF = 1e11;
	for (int i = 0; i < m; i++)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		c += INF;
		add_edge(u, v, c, c);
	}

	ll temp = max_flow(source, sink);
	if (!temp){
		cout << "0\n";
		cout << "0\n";
		return 0;	
	}
	

	vector<int>	ls = get(source);
	if (ls.size() > 2){
		cout << "-1\n";
		return 0;
	}

	if (ls.size() == 2){
		cout << temp - INF * 2 << "\n";
		cout << "2\n";
		cout << ls[0] + 1 << " " << ls[1] + 1 << "\n";
		return 0;
	}

	memset(vis, 0, sizeof(vis));
	ff(source);
	for (int e = 0; e < ec; e += 2)
		if (ced[e] | ced[e^1])
			cap[e] = cap[e^1] = INF * 4;

	ll temp2 = max_flow(source, sink);
	int xx = ls[0];
	ls = get(source);
	if (ls.size() > 2 || temp2 - INF * 2 >= temp - INF){
		cout << temp - INF << "\n";
		cout << "1\n";
		cout << xx + 1 << "\n";
		return 0;
	}

	cout << temp2 - INF * 2 << "\n";
	cout << "2\n";
	cout << ls[0] + 1 << " " << ls[1] + 1 << "\n";
	return 0;
}