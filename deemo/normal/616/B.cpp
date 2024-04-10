#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 4;

int n, m;
int a[MAXN][MAXN];

int main(){
	cin >> n >> m;
	int ans = 1;
	for (int i = 0; i < n; i++){
		int mini = 1e9;
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			mini = min(mini, a[i][j]);
		}
		ans = max(ans, mini);
	}
	cout << ans << endl;
	return	0;
}