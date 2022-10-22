#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
char c[100][100];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i % 2 == 0)
				c[i][j] = '#';
			else
				c[i][j] = '.';
	for (int i = 1; i < n; i += 4)
		c[i][m - 1] = '#';
	for (int i = 3; i < n; i += 4)
		c[i][0] = '#';
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << c[i][j];
		cout << endl;
	}
	return	0;
}