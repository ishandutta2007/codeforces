#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> G[101010];
bool chk[101010];
int n, m, ans;

void dfs(int p)
{
	chk[p] = 1;
	
	for(int &t: G[p]){
		if(!chk[t]){
			dfs(t);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, x, y;
	
	cin >> n >> m;
	
	for(i=0; i<m; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	for(i=1; i<=n; i++){
		if(!chk[i]){
			dfs(i);
			ans ++;
		}
	}
	
	cout << m - n + ans << "\n";
	
	return 0;
}