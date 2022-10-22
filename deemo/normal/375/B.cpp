#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<string>

using namespace std;

const int max_n = 5e3 + 30;

int n, m;
bool mat[max_n][max_n];
short pre[max_n][max_n];
int mark[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	string c;
	for (int i = 0; i < n; i++){
		cin >> c;
		for (int j = 0; j < m; j++)
			mat[i][j] = c[j] - 48;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (mat[i][j] == 0)	continue;
			if (j == 0 || mat[i][j - 1] == 0){
				pre[i][j] = j;
				continue;
			}
			pre[i][j] = pre[i][j - 1];
		}
	
	int ans = 0;
	for (int i = 0; i < m; i++){
		fill(mark, mark + m, 0);
		for (int j = 0; j < n; j++){
			if (mat[j][i] == 0)	continue;
			mark[pre[j][i]]++;
		}
		int sum = 0;
		for (int j = 0; j <= i; j++){
			sum += mark[j];
			ans = max(ans, sum * (i - j + 1));
		}
	}
	cout << ans << endl;
	return 0;
}