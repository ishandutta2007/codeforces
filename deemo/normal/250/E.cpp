#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 100 + 4;
const int MAXM = 1e4 + 10;

int n, m;
char c[MAXN][MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 1; j <= m; j++)
			c[i][j] = temp[j - 1];
		c[i][0] = c[i][m + 1] = '#';
	}

	int x = 0, y = 1, dir = 1;
	ll ans = 0;
	while (x != n - 1){
		bool found = 0;
		for (int j = y; c[x][j] != '#'; j--)
			if (c[x + 1][j] == '.')	found = 1;
		for (int j = y; c[x][j] != '#'; j++)
			if (c[x + 1][j] == '.')	found = 1;

		if (found == 0){
			cout << "Never\n";
			return	0;
		}
		if (c[x + 1][y] == '.'){
			ans++;
			x++;
			continue;
		}
	
		int l = y, r = y, cur = y;
		while (c[x + 1][cur] != '.'){
			if (dir == 1){
				if (c[x][cur + dir] == '#'){
					dir = -1;
					ans++;
				}	
				else if (c[x][cur + dir] == '+'){
					c[x][cur + dir] = '.';
					dir = -1;
					ans++;
				}
				else if (r > cur + dir){
					ans += r - cur;
					cur = r;
				}
				else{
					ans++;
					cur++;
					r = cur;
				}
			}
			else{
				if (c[x][cur + dir] == '#'){
					dir = 1;
					ans++;
				}
				else if (c[x][cur + dir] == '+'){
					ans++;
					c[x][cur + dir] = '.';
					dir = 1;
				}
				else if (l < cur + dir){
					ans += cur - l;
					cur = l;
				}
				else{
					ans++;
					cur--;
					l = cur;
				}
			}
		}
		x++;
		ans++;
		y = cur;
	}
	cout << ans << endl;
	return 0;
}