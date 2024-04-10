#include<iostream>
#include<algorithm>

using namespace std;

int row[20], col[20];

int main(){
	int n, m;	cin >> n >> m;
	int ans = n * m;
	char c[20][20];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if (c[i][j] == 'S')	row[i] = col[j] = 1;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (row[i] && col[j])	ans--;
	cout << ans << endl;
	return 0;
}