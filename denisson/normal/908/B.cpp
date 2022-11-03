#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, m;
char a[55][55];
string s;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	int sx, sy;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 'S') sx = i, sy = j;
	cin >> s;
	vector<int> t;
	for (int i = 0; i < 4; i++) t.pub(i);
	int ans = 0;
	do{
		int x = sx, y = sy;
		int f = 1, f2 = 0;
		for (int i = 0; i < s.size(); i++){
			x += dx[t[s[i] - '0']];
			y += dy[t[s[i] - '0']];
			if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#'){
				f = 0;
				break;
			}
			if (a[x][y] == 'E'){
				f2 = 1;
				break;
			}
		}
		if (f && f2) ans++;
	}while(next_permutation(all(t)));
	cout << ans;
}