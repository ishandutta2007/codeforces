#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n;
vector<int> adj[2][MAXN];
bool picked[MAXN];
int del[MAXN];

int cur = 0;
void go(){
	while (cur < n && del[cur]) cur++;
	if (cur == n) return;

	int v = cur++;
	del[v]++;
	picked[v] = true;

	for (int u:adj[0][v])
		del[u]++;

	go();
	bool mark = 0;
	for (int u:adj[1][v])
		if (picked[u])
			mark = true;
	if (mark)
		picked[v] = false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b, a--, b--;
		adj[0][a].push_back(b);
		adj[1][b].push_back(a);
	}
	go();

	int c = 0;
	for (int i = 0; i < n; i++)
		if (picked[i]) c++;
	cout << c << "\n";
	for (int i = 0; i < n; i++)
		if (picked[i])
			cout << i+1 << " ";
	cout << "\n";
	return 0;
}