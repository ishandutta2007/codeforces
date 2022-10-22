#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXL = 300;
const int C = 26;
const int INF = 1e9;

int n, a[MAXL];
ll l, ss[MAXL], val[MAXL];
int f[MAXL], nxt[C][MAXL], sz;
int q[MAXL];
vector<int>	adj[MAXL];

int insert(string t){
	int cur = 0;
	for (char c:t){
		if (nxt[c - 'a'][cur] == 0)
			nxt[c - 'a'][cur] = ++sz;
		cur = nxt[c - 'a'][cur];
	}
	return cur;
}

void aho(){
	int h = 0, t = 0;
	for (int w = 0; w < 26; w++)
		if (nxt[w][0])
			q[t++] = nxt[w][0];

	while (h < t){
		int v = q[h++];
		adj[f[v]].push_back(v);
		for (int w = 0; w < 26; w++)
			if (nxt[w][v]){
				f[nxt[w][v]] = nxt[w][f[v]];
				q[t++] = nxt[w][v];
			}
			else
				nxt[w][v] = nxt[w][f[v]];
	}
}

void plant(int v, ll x = 0){
	x += ss[v];
	val[v] = x;
	for (int u:adj[v])
		plant(u, x);
}

struct Mat{
	ll v[MAXL][MAXL];
	int n, m;
	Mat(int a, int b, int x = 0){
		n = a, m = b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)	v[i][j] = 0;
		for (int i = 0; i < n; i++)
			v[i][i] = x;
	}
};

Mat mul(Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)	ret.v[i][j] = -INF;
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int w = 0; w < a.m; w++)
				ret.v[i][j] = max(ret.v[i][j], a.v[i][w] + b.v[w][j]);
	return ret;
}

Mat pw(Mat a, ll b){
	Mat ret(a.n, a.m, 0);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++)
			if (i^j)
				ret.v[i][j] = -INF;
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		ss[insert(temp)] += a[i];
	}
	aho();
	plant(0);

	Mat ans(sz + 1, 1, 0);
	for (int i = 1; i <= sz; i++)	ans.v[i][0] = -INF;
	Mat v(sz + 1, sz + 1, 0);
	for (int i = 0; i <= sz; i++)	
		for (int j = 0; j <= sz; j++)
			v.v[i][j] = -INF;
	for (int i = 0; i <= sz; i++)
		for (int j = 0; j < C; j++)
			v.v[nxt[j][i]][i] = val[nxt[j][i]];

	ans = mul(pw(v, l), ans);

	ll ret = -INF;
	for (int i = 0; i <= sz; i++)
		ret = max(ret, ans.v[i][0]);
	cout << ret << "\n";
	return 0;
}