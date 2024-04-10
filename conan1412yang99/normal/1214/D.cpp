#include <bits/stdc++.h>
#define F first
#define S second
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair
#define EB emplace_back
 
using namespace std;
 
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long long ll;
 
const int P = 1e9 + 7;
 
string a[1000006];

vi vis[1000006], vis2[1000006];
int n, m;
 
bool dfs(int x, int y) {
	vis[x][y] = 1;
	if(x == n-1 && y == m-1) return true;
	bool ret = false;
	if(x+1<n && !vis[x+1][y] && a[x+1][y] == '.')
		ret |= dfs(x+1, y);
	if(y+1<m && !vis[x][y+1] && a[x][y+1] == '.')
		ret |= dfs(x, y+1);
	return ret;
}
 
void dfs2(int x, int y) {
	vis2[x][y] = 1;
	if(x-1>=0 && !vis2[x-1][y] && a[x-1][y] == '.')
		dfs2(x-1, y);
	if(y-1>=0 && !vis2[x][y-1] && a[x][y-1] == '.')
		dfs2(x, y-1);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		vis[i].resize(m);
		vis2[i].resize(m);
	}
	if(!dfs(0, 0)) {
		cout << 0 << endl;
		return 0;
	}
	dfs2(n-1, m-1);
	for(int i=1;i<n;i++) {
		int x = i, y = 0;
		int ct = 0;
		while(x>=0 && y < m) {
			ct += !(vis[x][y] == 0 || vis2[x][y] == 0);
			x--, y++;
		}
		if(ct <= 1) {
			cout << 1 << endl;
			return 0;
		}
	}
	for(int i=0;i<m-1;i++) {
		int x = n-1, y = i;
		int ct = 0;
		while(x>=0 && y < m) {
			ct += !(vis[x][y] == 0 || vis2[x][y] == 0);
			x--, y++;
		}
		if(ct <= 1) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
 
}