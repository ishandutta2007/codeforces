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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int perm[4] = {0,1,2,3},n,m;
string g[55];
int si,sj;
string inst;

bool good() {
	int i = si, j = sj;
	for(char c : inst) {
		int x = c-'0';
		i += dx[perm[x]];
		j += dy[perm[x]];
		if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#')
			return false;
		if(g[i][j] == 'E')
			return true;
	}
	return false;
}

int main() {	
	fio;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i) {
		cin >> g[i];
		for(int j = 0; j < m; ++j) {
			if(g[i][j] == 'S')
				si = i, sj = j;
		}
	}
	cin >> inst;
	int ans = 0;
	do {
		ans += good();
	} while(next_permutation(perm,perm+4));
	cout << ans << "\n";
}