#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 500 + 10;

int n, k, val[MAXN];
bool d[2][MAXN][MAXN];
int vec[MAXN], sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> val[i];
	sort(val, val + n);

	bool cur = 0;
	d[cur][0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int a = 0; a < MAXN; a++)
			for (int b = 0; b < MAXN; b++)
				d[!cur][a][b] = d[cur][a][b];

		for (int a = 0; a < MAXN; a++)
			for (int b = 0; b < MAXN; b++)
				if (a >= val[i])
					d[!cur][a][b] |= d[cur][a - val[i]][b];

		for (int a = 0; a < MAXN; a++)
			for (int b = 0; b < MAXN; b++)
				if (b >= val[i])
					d[!cur][a][b] |= d[cur][a][b - val[i]];

		cur = !cur;
	}

	for (int i = 0; i <= k; i++)
		if (d[cur][i][k - i])	
			vec[sz++] = i;

	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << vec[i] << " ";
	cout << "\n";
	return 0;
}