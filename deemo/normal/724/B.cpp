#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 20 + 3;

int n, m, x[MAXN][MAXN];

bool check(int a, int b){
	for (int i = 0; i < n; i++)
		swap(x[i][a], x[i][b]);

	int ret = 0;
	for (int i = 0; i < n; i++){
		int cnt = 0;
		for (int j = 0; j < m; j++)
			if (x[i][j] != j + 1)	cnt++;
		ret += bool(cnt < 3);
	}

	for (int i = 0; i < n; i++)
		swap(x[i][a], x[i][b]);
	return ret == n;
}

int main(){
	cin >> n >> m;
	int cc = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> x[i][j];

	for (int a = 0; a < m; a++)
		for (int b = a; b < m; b++)
			if (check(a, b)){
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";
	return 0;
}