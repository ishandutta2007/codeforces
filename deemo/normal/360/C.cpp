#include<iostream>
#include<string>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 10;
const int MOD = 1e9 + 7;

int n, k, tt, mark[MAXN];
string s;
ll c[MAXN][MAXN], d[MAXN][MAXN], e[MAXN][MAXN];

int main(){
	cin >> n >> k >> s;
	
	for (int i = 0; i < n; i++)	d[i][0] = 1;
	d[n][0] = 1;
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j <= k; j++){
			if (j){
				if (j >= n - i)
					e[i][j] = ll('z' - s[i]) * d[i + 1][j - (n - i)] % MOD;

				tt++;
				for (int w = i; w < n && (w - i) * (n - w) <= j; w++)
					d[i][j] = (d[i][j] + e[w][j - (w - i) * (n - w)]) % MOD, mark[w] = tt;

				for (int w = n - 1; mark[w] ^ tt && (w - i) * (n - w) <= j; w--)
					d[i][j] = (d[i][j] + e[w][j - (w - i) * (n - w)]) % MOD;
			}
			else
				d[i][j] = 1;

			c[i][j] = (c[i + 1][j] + ll(s[i] - 'a') * d[i + 1][j]) % MOD;
			d[i][j] = (d[i][j] + c[i][j]) % MOD;
		}

	cout << d[0][k] << "\n";
	return 0;
}