#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[55][55], p[55][55], dp[55][55][55][55];

int sm(int i, int j, int k, int l) {
	return p[k][l] - p[i-1][l] - p[k][j-1] + p[i-1][j-1];
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			char c;
			cin >> c;
			a[i][j] = c == '#';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j] = a[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=i;k<=n;k++)
				for(int l=j;l<=n;l++) {
					if(sm(i, j, k, l))
						dp[i][j][k][l] = max(k-i+1, l-j+1);
				}
	for(int h=1;h<=n;h++) {
		for(int w=1;w<=n;w++) {
			if(h == 1 && w == 1) continue;
			for(int i=1;i+h-1<=n;i++) {
				for(int j=1;j+w-1<=n;j++) {
					int k = i + h - 1, l = j + w - 1;
					if(h > w) {
						for(int c=i;c<=k;c++) {
							if(sm(c, j, c, l) == 0) {
								dp[i][j][k][l] = min(dp[i][j][k][l], (c == i ? 0 : dp[i][j][c-1][l]) + (c == k ? 0 : dp[c+1][j][k][l]));
							}
						}
					} else {
						for(int c=j;c<=l;c++) {
							if(sm(i, c, k, c) == 0) {
								dp[i][j][k][l] = min(dp[i][j][k][l], (c == j ? 0 : dp[i][j][k][c-1]) + (c == l ? 0 : dp[i][c+1][k][l]));
							}
						}
					}
				}
			}
		}
	}
	cout << dp[1][1][n][n] << endl;
}