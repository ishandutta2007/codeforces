#include<cstdio>
#include<string>//isn't cstring enough? :/ (I guess I'll never know :P)
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 20;
const int MAXM = 1e5 + 10;

int n, m, d[2][MAXN + 2][1<<MAXN], zz[MAXM];
char tt[MAXM];
string s[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", tt);
		s[i] = tt;
	}

	bool cur = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '0')
				zz[j] |= 1<<i;
	for (int j = 0; j < m; j++)
		d[cur][0][zz[j]]++;

	for (int w = 0; w < n; w++){
		cur = !cur;
		for (int j = 0; j <= w + 1; j++)
			for (int i = 0; i < (1<<n); i++){
				d[cur][j][i] = d[!cur][j][i];
				if (j)
					d[cur][j][i] += d[!cur][j - 1][i ^ (1<<w)];
			}
	}

	int mx = 0;
	for (int i = 0; i < (1<<n); i++){
		int temp = 0;
		for (int j = 0; j <= n; j++)
			temp += max(j, n - j) * d[cur][j][i];
		mx = max(mx, temp);
	}
	printf("%d\n", n * m - mx);
	return 0;
}