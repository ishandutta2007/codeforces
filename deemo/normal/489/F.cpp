#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 500 + 5;

int n, m, MOD;
string s[MAXN];
int d[2][MAXN][MAXN], cnt[MAXN];

ll choose(ll n){return n * (n - 1)/ 2;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> MOD;
	for (int i = 0; i < m; i++){
		cin >> s[i];
		for (int j = 0; j < n; j++)
			if (s[i][j] == '1')
				cnt[j]++;
	}

	int a = 0, b = 0;
	for (int j = 0; j < n; j++)
		if (cnt[j] == 0)	a++;
		else if (cnt[j] == 1)	b++;

	bool cur = 0;
	d[cur][a][b] = 1;//a -> 0, b -> 1
	for (int i = m; i < n; i++){
		for (int j = 0; j <= n; j++)
			for (int w = 0; w <= n; w++)
				d[!cur][j][w] = 0;

		for (int j = 0; j <= n; j++)
			for (int w = 0; w <= n; w++)
				if (d[cur][j][w]){
					if (j >= 2)
						d[!cur][j - 2][w + 2] = (d[!cur][j - 2][w+2] + choose(j) * d[cur][j][w]) % MOD;
					if (j && w)
						d[!cur][j - 1][w] = (d[!cur][j - 1][w] + ll(w) * ll(j) * d[cur][j][w]) % MOD;
					if (w >= 2)
						d[!cur][j][w - 2] = (d[!cur][j][w - 2] + choose(w) * d[cur][j][w]) % MOD;
				}
		cur = !cur;
	}
	cout << d[cur][0][0] << endl;
	return 0;
}