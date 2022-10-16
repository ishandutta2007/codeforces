#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

char a[55][55];
pi mp[5];
int n, m;

bool ok(string cmd, pi s) {
	int x = s.F, y = s.S;
	for(int i=0;i<cmd.size();i++) {
		int scmd = cmd[i] - '0';
		x += mp[scmd].F, y += mp[scmd].S;
		if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#')
			return false;
		if(a[x][y] == 'E')
			return true;
	}
	return false;
}

int main()
{
	IO_OP;
	

	string cmd;
	pi r = {0, 1}, l = {0, -1}, u =  {1, 0}, d = {-1, 0}, s;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S')
				s = {i, j};
		}
	cin >> cmd;
	int ans = 0;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(j == i) continue;
			for(int k=0;k<4;k++) {
				if(k == j || k == i) continue;
				for(int h=0;h<4;h++) {
					if(h == i || h == j || h == k) continue;
					mp[i] = r, mp[j] = l, mp[k] = u, mp[h] = d;	
					if(ok(cmd, s))
						ans++;
				}
			}
		}
	}
	cout << ans << endl;
}