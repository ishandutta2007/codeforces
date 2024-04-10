#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int n, m;
char c;
string s[MAXN];
bool mark[300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] != '.' && s[i][j] != c){
				bool found = 0;
				for (int w = 0; w < 4; w++)
					if (fit(i + dx[w], j + dy[w]) && s[i+dx[w]][j + dy[w]] == c)	found = 1;
				if (found)
					mark[s[i][j]] = 1;
			}
	int ans = 0;
	for (int i = 0; i < 200; i++)
		if (mark[i])	ans++;
	cout << ans << endl;
	return 0;
}