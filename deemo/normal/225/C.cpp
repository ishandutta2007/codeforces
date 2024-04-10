#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int max_n = 1e3 + 10;
const int INF = 1e9 + 7;

int n, m, l, r;
char c[max_n][max_n];
int cnt[max_n], d[max_n][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> l >> r;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++)
			c[i][j] = temp[j];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (c[j][i] == '#')	cnt[i + 1]++;
	
	for (int i = 1; i <l; i++)
		d[i][0] = d[i][1] = INF;

	for (int i = l; i <= m; i++){
		for (int t = 0; t < 2; t++){
			d[i][t] = INF;
			int sum = cnt[i];
			if (t == 0)	sum = n - sum;
			for (int j = i - 1; j >= 0 && j > i - l; j--)
				if (t)	sum += cnt[j];
				else	sum += n - cnt[j];

			for (int j = i - l; j >= 0 && j >= i - r; j--){
				d[i][t] = min(d[i][t], d[j][1 - t] + sum);
				if (t){
					if (j >= 0)	sum += cnt[j];
				}
				else	sum += n - cnt[j];
			}
		}
	}
	cout << min(d[m][0], d[m][1]) << endl;
	return 0;
}