#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 20;
const int INF = 1e9 + 2;

int n, vec[MAXN], d[MAXN][MAXN];
bool mark[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			d[i][j] = -INF;
	d[0][0] = 0;
	for (int i = 0; i < n; i++){
		int l = i - 1, sum = 0, ss = 0;
		memset(mark, 0, sizeof(mark));

		for (int j = i; j >= 0; j--){
			l = min(l, j - 1);
			int z = d[i + 1][j + 1];

			ss += vec[j];
			if (mark[j])
				sum -= vec[j], mark[j] = 0;
			while (l >= 0 && sum + vec[l] <= ss)	mark[l] = 1, sum += vec[l--];
			d[i + 1][j] = max(z, d[j][l + 1] + 1);
		}
	}
	cout << n - d[n][0] << "\n";
	return	0;	
}