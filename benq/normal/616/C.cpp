#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int components[1000][1000],n,m, num = 0;
int xdir[4] = {-1,0,1,0}, ydir[4] = {0,-1,0,1};
char grid[1000][1000];
int size[1000001];

bool ok(int x, int y) {
	if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] != '*') return 1;
	return 0;
}

void dfs(int x, int y) {
	size[num] = (size[num]+1) % 10;
	components[x][y] = num;
	F0R(i,4) if (ok(x+xdir[i],y+ydir[i]) && components[x+xdir[i]][y+ydir[i]] == 0) dfs(x+xdir[i],y+ydir[i]);
}

void print() {
	F0R(j,n) {
		F0R(i,m) cout << grid[i][j];
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	F0R(j,n) F0R(i,m) cin >> grid[i][j];

	F0R(j,n) F0R(i,m) {
		if (grid[i][j] == '.' && components[i][j] == 0) {
			num++;
			dfs(i,j);
		}
	}
	
	F0R(j,n) F0R(i,m) {
		if (grid[i][j] == '*') {
			set<int> asdf;
			F0R(k,4) {
				if (ok(i+xdir[k],j+ydir[k]) && asdf.find(components[i+xdir[k]][j+ydir[k]]) == asdf.end()) {
					asdf.insert(components[i+xdir[k]][j+ydir[k]]);
				}
			}
			int ans = 0;
			F0R(i,asdf.size()) ans += size[*next(asdf.begin(), i)];
			ans = (ans+1) % 10;
			grid[i][j] = char('0'+ans);
		}
	}
	print();
	return 0;
}