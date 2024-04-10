#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 6e3 + 20;

int n, ans, p[MAXN];
vector<int>	adj[MAXN], vec;

void get(int v, int par = -1){
	int pos = lower_bound(vec.begin(), vec.end(), p[v]) - vec.begin();
	bool fl = 0;
	int prv = 0;
	if (pos == vec.size())
		fl = 1, vec.push_back(p[v]);
	else
		prv = vec[pos], vec[pos] = p[v];

	for (int u:adj[v])
		if (u != par)	get(u, v);

	ans = max(ans, (int)vec.size());
	if (fl)
		vec.pop_back();
	else
		vec[pos] = prv;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (adj[i].size() == 1)	get(i);
	cout << ans << endl;
	return 0;	
}