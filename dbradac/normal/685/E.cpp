#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct strq {
	int poc, kraj, dokad, ind;
};

const int MAXN = 1005, MAXM = 201000;

int a[MAXM], b[MAXM];
int dist[MAXN][MAXN];
int rje[MAXM];
vector <strq> Q[MAXM];

int main()
{
	int n, m, q;

	scanf("%d%d%d", &n, &m, &q);

	for (int i=0; i<m; i++) {
		scanf("%d%d", &a[i], &b[i]); a[i]--; b[i]--;
	}

	for (int i=0; i<q; i++) {
		int kren, dokad, poc, kraj;
		scanf("%d%d%d%d", &kren, &dokad, &poc, &kraj);
		kren--; dokad--; poc--; kraj--;
		Q[kren].push_back(strq {poc, kraj, dokad, i});
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			dist[i][j] = MAXM;
		dist[i][i] = 0;
	}

	for (int i=m-1; i>=0; i--) {
		dist[a[i]][a[i]] = i;
		dist[b[i]][b[i]] = i;
		for (int j=0; j<n; j++) {
			dist[a[i]][j] = min(dist[a[i]][j], max(dist[b[i]][j], i));
			dist[b[i]][j] = min(dist[b[i]][j], max(dist[a[i]][j], i));
		}

		for (auto it : Q[i])
			rje[it.ind] = dist[it.poc][it.kraj] <= it.dokad;
	}

	for (int i=0; i<q; i++)
		printf("%s\n", rje[i] ? "Yes" : "No");

	return 0;
}