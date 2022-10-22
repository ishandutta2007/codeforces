#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 50 + 5;

int n, a[MAXN][MAXN], p[MAXN];

int main(){
	cin >> n;
	int ind = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (j < i && a[i][j] == n - 1)	ind = i;
		}
	p[ind] = n;
	for (int j = 0; j < n; j++)
		if (ind != j)
			p[j] = a[ind][j];
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
	return	0;
}