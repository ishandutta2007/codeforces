#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

ll ans[200007];
int n;
vector<int> g[200007];
int color[200007];

 
bool del[200007];
int w[200007];

ll sum[200007];
ll sum2[200007];
 
void dfsW(int v, int pred){
    w[v] = 1;
    sum[v] = 0;
    sum2[v] = 0;
    for (auto to : g[v]) if (!del[to] && to != pred){
        dfsW(to, v);
        w[v] += w[to];
    }
}
 
int findVert(int v, int pred, int ww){
    for (auto to : g[v]) if (!del[to] && to != pred && w[to] > ww / 2) return findVert(to, v, ww);
    return v;
}

//unordered_map<int, int> ma;
int ma[1 << 20];
 
void dfsFunc(int v, int pred, int mask, int zn){
	mask ^= (1 << color[v]);
	ma[mask] += zn;
	for (int to : g[v]) if (!del[to] && to != pred) dfsFunc(to, v, mask, zn);
}

void dfsCalcAns(int v, int pred, int mask){
	mask ^= (1 << color[v]);
	sum[v] += ma[mask];
	if (mask == 0) sum2[v]++;
	for (int i = 0; i < 20; i++){
		if (mask == (1 << i)) sum2[v]++;
		sum[v] += ma[mask ^ (1 << i)];
	}
	for (int to : g[v]) if (!del[to] && to != pred) dfsCalcAns(to, v, mask);
}

void dfsCalcSum(int v, int pred){
	for (int to : g[v]) if (!del[to] && to != pred){
		dfsCalcSum(to, v);
		sum[v] += sum[to];
		sum2[v] += sum2[to];
	}
	if (pred == -1) ans[v] += sum[v] / 2 + sum2[v];
	else ans[v] += sum[v] + sum2[v];
}

void build(int v){
    dfsW(v, -1);
    int cc = findVert(v, -1, w[v]);

    for (int to : g[cc]) if (!del[to]) dfsFunc(to, cc, 0, 1);

    for (int to : g[cc]) if (!del[to]){
    	dfsFunc(to, cc, 0, -1);
    	dfsCalcAns(to, cc, (1 << color[cc]));
    	dfsFunc(to, cc, 0, 1);
    }

    dfsCalcSum(cc, -1);

    for (int to : g[cc]) if (!del[to]){
    	dfsFunc(to, cc, 0, -1);
    }

    del[cc] = 1;
    for (auto to : g[cc]) if (!del[to]) build(to);
}

int main(){
	//srand(time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		color[i] = c - 'a';
	}
	build(0);
	for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}