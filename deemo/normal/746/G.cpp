//asdf
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, k, mx, t[MAXN], par[MAXN], pt[MAXN];
vector<int>	adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> mx >> k;
	t[0] = pt[0] = 1;
	for (int i = 1; i <= mx; i++)	cin >> t[i], pt[i] = pt[i - 1] + t[i];
	for (int i = 1; i <= mx; i++){
		int x = t[i - 1];
		int cur = 0;
		for (int j = pt[i - 1]; j < pt[i]; j++, cur = (cur+1==x?0:cur+1))
			par[j] = pt[i - 1] - t[i - 1] + cur, adj[par[j]].push_back(j);
	}
	int cc = 0;
	for (int i = 1; i < n; i++)
		if (adj[i].empty())	cc++;
	if (cc > k){
		cout << "-1\n";
		return 0;
	}

	for (int i = 1; cc < k && i <= mx; i++){
		int x = t[i - 1];
		for (int j = pt[i - 1]+1; cc < k && j < pt[i]; j++){
			int temp = 0;
			while (adj[j].size()){
				par[adj[j].back()] = pt[i - 1];
				adj[pt[i - 1]].push_back(adj[j].back());
				adj[j].pop_back();
				temp++;
			}
			if (temp)
				cc++;
			adj[j].resize(0);
		}
	}
	if (cc ^ k){
		cout << "-1\n";
		return 0;
	}
	
	cout << n << "\n";
	for (int i = 1; i < n; i++)
		cout << i+1 << " " << par[i]+1 << "\n";
	return 0;
}