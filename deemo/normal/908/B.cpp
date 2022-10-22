#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 10;

int n, m;
string s[MAXN], t;
int sec[4] = {0, 1, 2, 3};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool fit(int x, int y){return 0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#';}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	pii ss;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'S')
				ss = {i, j};
	}

	cin >> t;
	int ans = 0;
	do {
		pii cur = ss;
		for (char c:t){
			int z = c - '0';
			cur.F += dx[sec[z]], cur.S += dy[sec[z]];
			if (!fit(cur.F, cur.S))
				break;
			if (s[cur.F][cur.S] == 'E') {
				ans++;
				break;
			}
		}
	}while (next_permutation(sec, sec + 4));
	cout << ans << endl;
	return 0;
}