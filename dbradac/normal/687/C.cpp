#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 505;

int dp[2][MAX][MAX];
int p[MAX];

int main()
{
	int n, uk;

	scanf("%d%d", &n, &uk);

	for (int i=0; i<n; i++)
		scanf("%d", &p[i]);

	dp[0][0][0] = 1;

	int ind = 0;
	for (int i=0; i<n; i++, ind^=1) {
		memcpy(dp[1^ind], dp[ind], sizeof dp[1^ind]);
		for (int j=0; j<=uk-p[i]; j++) {
			for (int k=0; k<=uk-p[i]; k++) {
				dp[1^ind][j][k+p[i]] |= dp[ind][j][k];
				dp[1^ind][j+p[i]][k+p[i]] |= dp[ind][j][k];
			}
		}
	}

	vector <int> R;
	for (int i=0; i<=uk; i++)
		if (dp[ind][i][uk])
			R.push_back(i);

	printf("%d\n", (int) R.size());
	for (auto it : R)
		printf("%d ", it);
	printf("\n");

	return 0;
}