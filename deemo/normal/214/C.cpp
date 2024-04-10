#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<cassert>

using namespace std;

const int MAXN = 450 + 30;
const int INF = 1e9 + 7;

int n;
bool mark[MAXN];
vector<int>	adj[MAXN], sadj[MAXN];
vector<int>	st;
vector<int>	comp[3];
int col[MAXN];

void dfs(int v){
	if (mark[v])
		return;
	mark[v] = 1;
	for (int u:adj[v])
		dfs(u);
	st.push_back(v);
}	

bool cmp(int a, int b){
	return	col[a] < col[b];
}

int uu, vv;
bool flag;
int ret = 0, cn = 0;

int get(int s){
	ret = cn = 0;
	memset(mark, 0, sizeof(mark));
	for (; cn < n; s = (s + 1) % 3, ret++){
		for (int i = 0; i < comp[s].size(); i++){
			uu = comp[s][i];
			if (mark[uu])	continue;
			flag = 1;
			for (int j = 0; j < sadj[uu].size(); j++){
				vv = sadj[uu][j];
				if (!mark[vv]){
					flag = 0;
					break;
				}
			}
			if (flag){
				mark[uu] = 1;
				cn++;
			}
		}
	}
	ret--;
	return	ret + n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;	temp--;
		comp[temp].push_back(i);
	}
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		for (int j = 0; j < t; j++){
			int v;	cin >> v;	v--;
			adj[v].push_back(i);
			sadj[i].push_back(v);
		}
	}

	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i);
	reverse(st.begin(), st.end());
	for (int i = 0; i < st.size(); i++)
		col[st[i]] = i;
	st.clear();

	for (int i = 0; i < 3; i++)
		sort(comp[i].begin(), comp[i].end(), cmp);

	int ans = min(get(0), get(1));
	ans = min(ans, get(2));
	cout << ans << endl;
	return 0;
}