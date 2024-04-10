//I've cried enough tears to see my own reflection in them..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<utility>
#include<cstring>

using namespace std;

const int MAX = 1e5 + 40;
const int MAXE = 3e5 + 400;
const int MAXN = 800 + 50;
const int INF = 1e9 + 5;

int n, ec, cnt;
int from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], prv[2 * MAXE];
int head[MAXN], age[MAXN];
bool mark[MAXN];
vector<int>	od, ev, ans[MAXN], sec[MAXN], adj[MAXN];
bool pr[MAX];
int fs[2 * MAXE];

void init(){
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAX; i++)
		for (int j = i + i; j < MAX; j += i)
			pr[j] = 1;
	memset(head, -1, sizeof(mark));
}

void add_edge(int u, int v, int uv, int vu = 0){
	fs[ec] = uv;
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u]; head[u] = ec++;
	fs[ec] = vu;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
}

int dfs(int v, int sink, int mini = INF){
	if (v == sink)	return	mini;
	if (mark[v])	return	0;
	mark[v] = 1;
	for (int e = head[v]; e != -1; e = prv[e])
		if (cap[e]){
			int x = dfs(to[e], sink, min(mini, cap[e]));
			if (x == 0)	continue;
			cap[e] -= x;
			cap[e ^ 1] += x;
			return	x;
		}
	return 0;
}

int max_flow(int root, int sink){
	memset(mark, 0, sizeof(mark));
	int ret = 0, x;

	while ((x = dfs(root, sink))){
		ret += x;
		memset(mark, 0, sizeof(mark));
	}
	return	ret;
}

void get(int v){
	if (mark[v])	return;
	mark[v] = 1;
	ans[cnt].push_back(v);
	
	for (int u:sec[v])	get(u);
}

int main(){
	init();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> age[i];
		if (age[i] % 2 == 0)	ev.push_back(i);
		else	od.push_back(i);
	}

	for (int i = 0; i < ev.size(); i++)
		for (int j = 0; j < od.size(); j++)
			if (!pr[age[ev[i]] + age[od[j]]])
				add_edge(ev[i], od[j], 1);
	int temp = ec;
			

	for (int u:ev)
		add_edge(n, u, 2);
	for (int u:od)
		add_edge(u, n + 1, 2);

	if (od.size() != ev.size() || max_flow(n, n + 1) != 2 * (int)ev.size())
		cout << "Impossible\n";
	else{
		for (int i = 0; i < temp; i += 2)
			if (fs[i] != cap[i]){
				sec[from[i]].push_back(to[i]);
				sec[to[i]].push_back(from[i]);
			}

		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < n; i++)
			if (!mark[i])
				get(i), cnt++;

		cout << cnt << endl;
		for (int i = 0; i < cnt; i++){
			cout << ans[i].size() << " ";
			for (int u:ans[i])
				cout << u + 1 << " ";
			cout << endl;
		}
	}
	return 0;
}