#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<iomanip>
#include<iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb(x) push_back(x)
#define Segment pair<pair<int, int>, pair<ld, int>>
#define left first.first
#define right first.second
#define id second.second
#define prob second.first

const int max_q = 5e3 + 100;
const int max_n = 2e5;

int seg[4 * max_n];
int n, q;
vector<int>	vec;
vector<Segment>	sec;
ld d[max_q][max_q];
vector<int>	adj[max_q];
int save[max_q];

void init(int v, int b, int e){
	if (e - b == 1){
		seg[v] = vec[b];
		return;
	}
	int mid = (b + e)/ 2;
	init(v<<1, b, mid);
	init(v<<1^1, mid, e);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)
		return	seg[v];
	if (r <= b || e <= l)
		return	-1;
	int mid = (b + e)/ 2;
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void dfs(int v){
	save[v] = get(1, 0, n, sec[v].left, sec[v].right);
	if (adj[v].size() == 0){
		d[v][0] = 1.0 - sec[v].prob;
		for (int i = 1; i <= q; i++)
			d[v][i] = 1.0;
		return;
	}

	for (int u:adj[v])
		dfs(u);
	
	for (int i = 0; i <= q; i++){
		ld t = sec[v].prob;
		for (int u:adj[v]){
			if (save[v] + i - save[u] - 1 > q)	continue;
			if (save[v] + i - save[u] - 1 < 0)
			{
				t = 0;
				break;
			}
			t *= d[u][save[v] + i - save[u] - 1];
		}
		if (i != 0)
			d[v][i] = t;
		t = 1.0 - sec[v].prob;
		for (int u:adj[v]){
			if (save[v] + i - save[u] > q)	continue;
			if (save[v] + i - save[u] < 0)
			{
				t = 0;
				break;
			}
			t *= d[u][save[v] + i - save[u]];
		}
		d[v][i] += t;
	}		
}

bool cmp(Segment a, Segment b){
	if (a.left != b.left)
		return	a.left < b.left;
	if (a.right != b.right)	
		return	a.right > b.right;
	return	a.id < b.id;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	cin >> n >> q;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	init(1, 0, n);

	q++;
	sec.resize(q);
	sec[0] = {{0, n}, {0, 0}};
	for (int i = 1; i < q; i++){
		cin >> sec[i].left >> sec[i].right >> sec[i].prob;
		sec[i].left--;
		sec[i].id = i;
	}	
	
	sort(sec.begin(), sec.end(), cmp);

	for (int i = 0; i < q; i++){
		int ind = -1; 
		for (int j = 0; j < i; j++){
			if (sec[j].left <= sec[i].left && sec[i].right <= sec[j].right)
				ind = j;
		}
		if (ind != -1)
			adj[ind].pb(i);
	}

	dfs(0);

	ld t = d[0][0] * save[0];
	for (int i = 1; i <= q; i++)
		t += (d[0][i] - d[0][i - 1]) * (save[0] + i);
	cout << t << endl;
	return 0;
}