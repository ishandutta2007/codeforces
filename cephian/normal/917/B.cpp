#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vector<vector<int>> C;
vector<vector<int>> G;

bool dp[105][105][26] = {};
bool fl[105][105][26] = {};

bool solve(int a, int b, int c) {
	// if(b < a) return solve(b,a,c);
	if(fl[a][b][c]) return dp[a][b][c];
	fl[a][b][c] = true;
	for(int i = 0; i < G[a].size(); ++i) {
		if(C[a][i] < c) continue;
		if(!solve(b,G[a][i],C[a][i])) {
			return dp[a][b][c] = true;
		}
	}
	return false;
}

int main() {	
	int n,m;
	scanf("%d%d",&n,&m);
	C.resize(n);
	G.resize(n);
	for(int i = 0; i < m; ++i) {
		int a,b;
		char c[10];
		scanf("%d%d%s",&a,&b,c),--a,--b;
		G[a].push_back(b);
		C[a].push_back(c[0]-'a');
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(solve(i,j,0)) printf("A");
			else printf("B");
		}
		printf("\n");
	}
}