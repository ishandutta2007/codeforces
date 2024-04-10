#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int v[N], u[N];
bool used[N];
vector <int> vec[N];
int dep[N], und[N], sco[N];

void DFS(int x){
	used[x] = true;
	for (int i = 0; i < vec[x].size(); i++){
		if (used[vec[x][i]])
			continue;
		dep[vec[x][i]] = dep[x] + 1;
		DFS(vec[x][i]);
		und[x] += und[vec[x][i]] + 1;
	}
}

int32_t main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		cin >> v[i] >> u[i];
		vec[v[i]].push_back(u[i]);
		vec[u[i]].push_back(v[i]);
	}
	DFS(1);
	for (int i = 1; i <= n; i++){
		sco[i] = dep[i] - und[i];
	}
	sort(sco + 1, sco + n + 1);
	reverse (sco + 1, sco + n + 1);
	int ans = 0;
	for (int i = 1; i <= k; i++){
		ans += sco[i];
	}
	cout << ans;
}