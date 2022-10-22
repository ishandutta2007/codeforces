#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

const int MAXN = 1e5 + 20;
const int SQRT = 320;

int n, q;
int s_t[MAXN], f_t[MAXN], cc, comp[MAXN];
vector<int>	adj[MAXN];
bool mark[MAXN];
pair<int, int>	vec[MAXN], mp[MAXN];
pair<pair<int, int>, pair<int, int>>	query[MAXN];
int cn, sz;
int ans[MAXN], t[MAXN];

void dfs(int v){
	s_t[v] = cc++;
	for (int u:adj[v])	dfs(u);
	f_t[v] = cc;
}

void input(){
	cin >> n >> q;
	for (int i = 0; i < q; i++){
		cin >> t[i];
		if (t[i] == 1){
			cin >> vec[i].first >> vec[i].second;	
			vec[i].first--, vec[i].second--;
			adj[vec[i].second].push_back(vec[i].first);
			mark[vec[i].first] = 1;
			continue;
		}
		if (t[i] == 2){
			int x;	cin >> x;	x--;
			mp[cn++] = {i, x};
		}
		else{
			int a, b;	cin >> a >> b;	a--;	b--;
			query[sz++] = {mp[b], {a, i}};
		}
	}

	for (int i =0 ; i < n; i++)
		if (!mark[i])	dfs(i);
}

void init(){
	sort(query, query + sz);
	fill(ans, ans + q, -1);
}	

int get_comp(int v){
	if (v == comp[v])	return	v;
	return	comp[v] = get_comp(comp[v]);
}

void join(int u, int v){comp[get_comp(u)] = get_comp(v);}
bool check(int u, int v){return	get_comp(u) == get_comp(v) && s_t[u] <= s_t[v] && f_t[u] >= f_t[v];}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	init();
	iota(comp, comp + n, 0);

	int b = 0;
	for (int i = 0; i < q; i++){
		if (t[i] == 1)
			join(vec[i].first, vec[i].second);
		
		while (b < sz && query[b].first.first == i)
			ans[query[b].second.second] = check(query[b].second.first, query[b].first.second), b++;
	}

	for (int i = 0; i < q; i++)
		if (ans[i] != -1){
			if (ans[i])	
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	return	0;
}