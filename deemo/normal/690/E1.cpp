#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int MAXN = 600 + 5;

int n, m;
int c[MAXN][MAXN];

int main(){
	int q;	scanf("%d", &q);
	while (q--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &c[i][j]);

		int cnt = 0;
		int k = n/2;
		for (int j = 0; j < m; j++)
			if (abs(c[k][j] - c[k - 1][j]) < abs(c[0][j] - c[n - 1][j]))	cnt++;
		if (cnt > n/2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}