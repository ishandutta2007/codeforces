//#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 5;
const int XX = 1e4 + 10;

int n, x, a[MAXN], d[MAXN][XX];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> x;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j <= x; j++){
			d[i][j] = d[i + 1][j];
			if ((n - i) * a[i] <= j)
				d[i][j] = max(d[i][j], d[i + 1][j - (n - i) * a[i]] + 1);
		}
	cout << d[0][x] << "\n";
	return 0;
}