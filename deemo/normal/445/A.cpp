#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 3;

int n, m;
char c[MAXN][MAXN], d[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if ((i + j) % 2 == 1)	d[i][j] = 'W';
			else	d[i][j] = 'B';
			if (c[i][j] == '-')	d[i][j] = '-';
			cout << d[i][j];
		}
		cout << endl;
	}
	return	0;
}