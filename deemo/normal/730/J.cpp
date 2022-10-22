#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 1;
const int C = 1e4 + 2;

int n, a[MAXN], b[MAXN];
int d[2][MAXN][2 * C];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];

	memset(d, 63, sizeof(d));
	bool cur = 0;
	d[cur][0][C] = 0;
	for (int i = 0; i < n; i++, cur = !cur){
		for (int w = 0; w <= i; w++)
			for (int j = 0; j < 2 * C; j++)
				d[!cur][w][j] = 1e9;

		int rem = b[i] - a[i];
		for (int w = 0; w <= i; w++){
			for (int j = 0; j < 2 * C; j++)
				if (d[cur][w][j] < 1e8){
					int temp = j - C;
					d[!cur][w + 1][j + rem] = min(d[!cur][w + 1][j + rem], d[cur][w][j]);
					d[!cur][w][j - a[i]] = min(d[!cur][w][j - a[i]], d[cur][w][j] + a[i]);
				}
		}
	}
	
	pair<int, int>	mn(2e9, 2e9);
	for (int w = 0; w <= n; w++)
		for (int j = C; j < 2 * C; j++)
			if (d[cur][w][j] < 1e9)
				mn = min(mn, {w, d[cur][w][j]});
	cout << mn.first << " " << mn.second << endl;
	return 0;
}