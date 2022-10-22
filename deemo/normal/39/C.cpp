//Hameh goftan ke to rafti, Vali goftam ke Doroughe..

#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, l[MAXN], r[MAXN], sec[MAXN];
int c[MAXN], d[MAXN], par[MAXN];
vector<int>	adj[MAXN], ans;

bool cmp(int u, int v){
	if (r[u] ^ r[v])
		return r[u] < r[v];
	return l[u] > l[v];
}

int vec[MAXN], sz;
pair<int, int>	e[MAXN];

void cal(int v){
	sz = 0;
	for (int i = 0; i < v; i++)
		if (l[sec[v]] <= l[sec[i]] && r[sec[i]] <= r[sec[v]])	vec[sz++] = i;
	for (int i = 0; i < sz; i++){
		int v = vec[i];
		int temp = c[v];
		par[i] = -1;
		
		int beg = 0, end = i - 1, ret = -1;
		while (beg <= end){
			int mid = beg + end >> 1;
			if (r[sec[vec[mid]]] <= l[sec[v]])
				ret = mid, beg = mid + 1;
			else
				end = mid - 1;
		}

		if (~ret){
			temp += e[ret].F;
			par[i] = e[ret].S;
		}

		if (!i)
			e[i] = {temp, i};
		else
			e[i] = max(e[i - 1], {temp, i});
	}
	if (sz)	c[v] = e[sz - 1].F;
	c[v]++;

	int u = v;
	if (sz){
		v = e[sz - 1].S;
		while (~v){
			adj[u].push_back(vec[v]);
			v = par[v];
		}
	}
}

void go(int v){
	ans.push_back(sec[v] + 1);
	for (int u:adj[v])
		go(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b;
		l[i] = a - b, r[i] = a + b;
	}
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	for (int i = 0; i < n; i++)	cal(i);
	
	int mx = 0;
	for (int i = 0; i < n; i++){
		d[i] = c[i];
		par[i] = -1;
		for (int j = 0; j < i; j++)
			if (r[sec[j]] <= l[sec[i]])
				d[i] = max(d[i], c[i] + d[j]);
		
		for (int j = 0; j < i; j++)
			if (r[sec[j]] <= l[sec[i]] && d[i] == c[i] + d[j]){
				par[i] = j;
				break;
			}
		mx = max(mx, d[i]);
	}

	for (int i = 0; i < n; i++)
		if (mx == d[i]){
			int v = i;
			while (~v){
				go(v);
				v = par[v];
			}
			break;
		}

	cout << ans.size() << "\n";
	for (int v:ans)
		cout << v << " ";
	cout << "\n";
	return 0;
}