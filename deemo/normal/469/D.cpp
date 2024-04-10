#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int MAXN = 3e5 + 20;

int n, A, B, vec[MAXN], sz, col[MAXN], ans[MAXN], g;
bool vis[MAXN];
map<int, int>	mp;
vector<int>	adj[MAXN], sadj[MAXN], st, sst;

void add_clause(int u, int v){
	int uu = u;
	if (uu >= n)	uu -= n;	
	else	uu += n;

	int vv = v;
	if (vv >= n)	vv -= n;
	else	vv += n;

	adj[uu].push_back(v);
	sadj[v].push_back(uu);

	adj[vv].push_back(u);
	sadj[u].push_back(vv);
}

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:adj[v])
		dfs(u);
	st.push_back(v);
}

void kosaraju(int v, int c){
	if (col[v])	return;
	col[v] = c;
	for (int u:sadj[v])	
		kosaraju(u, c);
	sst.push_back(v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//input
	cin >> n >> A >> B;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		mp[vec[i]] = i;
	}

	//adding clauses
	for (int i = 0; i < n; i++){
		if (mp.count(A - vec[i]) == 0)
			add_clause(mp[vec[i]] + n, mp[vec[i]] + n);
		else{
			add_clause(mp[vec[i]], mp[A - vec[i]] + n);
			add_clause(mp[vec[i]] + n, mp[A - vec[i]]);
		}

		if (mp.count(B - vec[i]) == 0)
			add_clause(mp[vec[i]], mp[vec[i]]);
		else{
			add_clause(mp[vec[i]], mp[B - vec[i]] + n);
			add_clause(mp[vec[i]] + n, mp[B - vec[i]]);
		}
	}

	//finding components
	for (int i = 0; i < 2 * n; i++)
		if (!vis[i])	dfs(i);
	reverse(st.begin(), st.end());
	for (int v:st)
		if (col[v] == 0)	kosaraju(v, ++g);


	for (int i = 0; i < n; i++)
		if (col[i] == col[i + n]){
			cout << "NO\n";
			return	0;
		}

	//setting values
	reverse(sst.begin(), sst.end());
	cout << "YES\n";
	for (int v:sst){
		if (ans[col[v]])	continue;
		int u = v;
		if (v < n)	u += n;
		else	u -= n;
		if (ans[col[u]]){
			ans[col[v]] = 3 - ans[col[u]];
			continue;
		}

		ans[col[v]] = 1;
	}

	//output
	for (int i = 0; i < n; i++)
		if (ans[col[mp[vec[i]]]] == 1)
			cout << 0 << " ";
		else
			cout << 1 << " ";
	cout << "\n";
	return	0;
}