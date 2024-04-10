#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 2;

int n, m;
vector<int>	adj[MAXN], ans;
int sec[MAXN], cnt[MAXN];
int q[MAXN], h, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++){
		cin >> sec[i];
		if (sec[i] == cnt[i])	q[t++] = i;
	}

	while (h < t){
		int v = q[h++];
		ans.push_back(v + 1);
		cnt[v]++;

		for (int u:adj[v]){
			cnt[u]++;
			if (cnt[u] == sec[u])
				q[t++] = u;
		}	
	}
	cout << (int)ans.size() << endl;
	for (int v:ans)
		cout << v << " ";
	cout << endl;
	return 0;
}