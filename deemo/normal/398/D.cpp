#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

const int SQRT = 500;
const int MAXN = 5e4 + 10;
const int MAXQ = 25e4 + 10;

int n, m, q;
vector<int>	adj[MAXN], ls;
bool ln[MAXN], picked[MAXN];
int cnt[MAXN], pos[MAXN];
bool mark[2 * SQRT][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	int o;	cin >> o;
	while (o--){
		int temp;	cin >> temp;	temp--;
		ln[temp] = 1;
	}
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		if ((int)adj[i].size() >= SQRT){
			picked[i] = 1;
			int z = pos[i] = (int)ls.size();
			ls.push_back(i);
			for (int u:adj[i])
				mark[z][u] = 1;
		}

	for (int i = 0; i < n; i++)
		for (int u:adj[i])
			if (!picked[u] && ln[u])
				cnt[i]++;

	while (q--){
		char type;	int u;	cin >> type >> u;	u--;
		if (type == 'O'){
			ln[u] = 1;
			if (!picked[u])
				for (int v:adj[u])
					cnt[v]++;
		}
		else if (type == 'F'){
			ln[u] = 0;
			if (!picked[u])
				for (int v:adj[u])
					cnt[v]--;
		}
		else if (type == 'C'){
			int ret = cnt[u];
			for (int i = 0; i < (int)ls.size(); i++)
				if (mark[i][u] && ln[ls[i]])	ret++;
			cout << ret << "\n";
		}
		else if (type == 'D'){
			int v;	cin >> v;	v--;
			if (picked[u])
				mark[pos[u]][v] = 0;
			else{
				adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
				if (ln[u])	cnt[v]--;
			}

			if (picked[v])
				mark[pos[v]][u] = 0;
			else{
				adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
				if (ln[v])	cnt[u]--;
			}
		}	
		else{
			int v;	cin >> v;	v--;
			if (picked[u])
				mark[pos[u]][v] = 1;
			else{
				adj[u].push_back(v);
				if (ln[u])	cnt[v]++;
				if ((int)adj[u].size() >= SQRT){
					picked[u] = 1;
					pos[u] = (int)ls.size();
					int z = (int)ls.size();
					ls.push_back(u);
					if (ln[u])
						for (int w:adj[u])
							cnt[w]--;
				}
			}	

			if (picked[v])
				mark[pos[v]][u] = 1;
			else{
				adj[v].push_back(u);
				if (ln[v])	cnt[u]++;
				if ((int)adj[v].size() >= SQRT){
					picked[v] = 1;
					pos[v] = (int)ls.size();
					int z = pos[v];
					ls.push_back(v);
					if (ln[v])
						for (int w:adj[v])
							cnt[w]--;
				}
			}
		}	
	}		
	return 0;
}