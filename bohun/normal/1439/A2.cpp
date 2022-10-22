#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int N = 111;

int T, n, m, t[N][N];
char s[N][N];
vector<vector<int>> res;

void flip(int x1, int y1, int x2, int y2, int x3, int y3) {
	res.push_back({x1, y1, x2, y2, x3, y3});
	t[x1][y1] ^= 1;
	t[x2][y2] ^= 1;
	t[x3][y3] ^= 1;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		res.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s[i] + 1);
			for (int j = 1; j <= m; ++j)
				t[i][j] = s[i][j] - '0';
		}
		
		for (int i = n; 3 <= i; --i)
			for (int j = 1; j <= m; ++j) {
				if (t[i][j] == 0) continue;
				if (j == 1) 
					flip(i, j, i - 1, j, i - 1, j + 1);
				else
					flip(i, j, i - 1, j, i - 1, j - 1);
			}
			
		for (int j = m; 3 <= j; --j)
			for (int i = 1; i <= 2; ++i)
				if (t[i][j] == 1) 
					flip(i, j, 1, j - 1, 2, j - 1);
					
		if (t[2][2] == 1) 
			flip(1, 1, 1, 2, 2, 2);
		if (t[1][1] + t[1][2] + t[2][1] == 1)
			flip(1, 1, 1, 2, 2, 1);
		
		if (t[1][1] + t[1][2] == 2 && t[2][1] == 0) 
			flip(2, 2, 2, 1, 1, 1);
		else if (t[1][1] + t[2][1] == 2 && t[1][2] == 0) 
			flip(2, 2, 1, 2, 1, 1);
		else if (t[1][2] + t[2][1] == 2 && t[1][1] == 0) 
			flip(2, 2, 1, 1, 1, 2);
			
		if (t[1][1] + t[1][2] + t[2][1] == 3)
			flip(1, 1, 1, 2, 2, 1);
		if (t[1][1] + t[1][2] + t[2][2] == 3)
			flip(1, 1, 1, 2, 2, 2);
		if (t[1][1] + t[2][1] + t[2][2] == 3)
			flip(1, 1, 2, 1, 2, 2);
		if (t[1][2] + t[2][1] + t[2][2] == 3)
			flip(1, 2, 2, 1, 2, 2);
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				assert(t[i][j] == 0);
		assert(sz(res) <= n * m);
		printf("%d\n", sz(res));
		for (auto a : res) {
			for (auto b : a)
				printf("%d ", b);
			puts("");
		}
	}
				
	
	return 0;
}