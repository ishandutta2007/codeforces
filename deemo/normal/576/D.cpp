#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 150 + 2;
const int INF = 2e9 + 10;

struct Mat{
	bitset<MAXN> v[MAXN];
	int n, m;
	Mat(int n, int m):n(n), m(m){}
};

int n, m;
int from[MAXN], to[MAXN], t[MAXN], d[MAXN];
vector<int>	adj[MAXN];
int ed[MAXN];
bitset<MAXN> can;
Mat dj(MAXN, MAXN);

bool cmp(int e1, int e2){return t[e1] < t[e2];}

int q[MAXN], lv[MAXN];

void upd(int cur){
	fill(lv, lv + n, INF);
	int head = 0, tale = 0;
	for (int i = 0; i < n; i++)
		if (can[i])
			q[tale++] = i, lv[i] = cur;

	while (head < tale){
		int v = q[head++];
		for (int u:adj[v])
			if (lv[u] > lv[v] + 1){
				lv[u] = lv[v] + 1;
				q[tale++] = u;
			}
	}
	for (int i = 0; i < n; i++)
		d[i] = min(d[i], lv[i]);
}

bitset<MAXN> f[MAXN], g[MAXN], ttg;
Mat mul(Mat &a, Mat &b){
	Mat ret(a.n, b.m);
	for (int i = 0; i < a.n; i++)	f[i] = a.v[i];
	for (int j = 0; j < b.m; j++)
		for (int i = 0; i < b.n; i++)	g[j][i] = b.v[i][j];
	
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++){
			ttg = f[i] & g[j];
			ret.v[i][j] = ttg.count();
		}
	return ret;
}

bitset<MAXN> temp;
void go(int x, int e){
	Mat v(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	
			v.v[i][j] = dj.v[i][j];

	if (x){
		Mat ret(n, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret.v[i] = v.v[i];
		x--;
		while (x){
			if (x & 1)
				ret = mul(v, ret);
			x >>= 1;
			v = mul(v, v);
		}

		temp.reset();
		for (int i = 0; i < n; i++)
			for (int w = 0; !temp[i] && w < n; w++)
				temp[i] = ret.v[i][w] & can[w];
		can = temp;
	}
	adj[from[e]].push_back(to[e]);
	dj.v[to[e]][from[e]] = 1;
}

int main(){
	fill(d, d + MAXN, INF);
	cin >> n >> m;
	dj.n = dj.m = n;
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i] >> t[i], from[i]--, to[i]--;

	can[0] = 1;
	upd(0);
	iota(ed, ed + m, 0);
	sort(ed, ed + m, cmp);
	for (int i = 0; i < m; i++)
		go(i?t[ed[i]] - t[ed[i - 1]]:t[ed[i]], ed[i]), upd(t[ed[i]]);

	if (d[n - 1] == INF)
		cout << "Impossible\n";
	else
		cout << d[n - 1] << "\n";
	return 0;
}