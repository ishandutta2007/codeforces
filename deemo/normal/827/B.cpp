#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, k, d[MAXN];
vector<int> adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++)
		if (i-k < 1)
			adj[0].push_back(i), d[i] = d[0]+1;
		else
			adj[i-k].push_back(i), d[i] = d[i-k]+1;
	cout << d[n-1] + d[n-2] << "\n";
	for (int i = 0; i < n; i++)
		for (int j:adj[i])
			cout << i+1 << " " << j+1 << "\n";
	return 0;
}