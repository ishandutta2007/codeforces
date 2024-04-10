#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e3 + 10;
const int INF = 1e9;

int n, a[MAXN], d[2][MAXN][2][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n, n++;
	a[0] = -1e6;
	for (int i = 1; i < n; i++) cin >> a[i];

	memset(d, 63, sizeof(d));
	int cur = 0;
	d[cur][0][0][0] = d[cur][0][0][1] = 0;
	for (int i = 1; i < n; i++, cur = !cur)
		for (int j = 0; j <= i+1>>1; j++){
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					d[!cur][j][a][b] = INF;

			if (j)
				d[!cur][j][1][0] = (a[i-1] >= a[i]? d[cur][j-1][0][1]: min(d[cur][j-1][0][0], d[cur][j-1][0][1])) + max(0, a[i-1] - a[i] + 1);

			d[!cur][j][0][0] = min(max(0, a[i] - a[i-1] + 1) + d[cur][j][1][0], d[cur][j][0][0]);
			if (i+1 < n){
				int temp = min(a[i], a[i+1] - 1);
				d[!cur][j][0][1] = min(max(0, temp - a[i-1] + 1) + d[cur][j][1][0], d[cur][j][0][0]); 
			}
		}
	
	for (int k = 1; k <= n>>1; k++){
		int ans = 1e9;
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				ans = min(ans, d[cur][k][a][b]);
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}