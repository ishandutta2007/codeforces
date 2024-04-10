#include<iostream>
#include<algorithm>

using namespace std;

int n, x, a[4][10000];

int main(){
	cin >> n >> x;
	int cur = 1;
	for (int i = 0; i < min(x, 2 * n); i++){
		if (i % 2 == 0)
			a[0][i/2] = cur++;
		else
			a[3][i/2] = cur++;
	}
	for (int i = 2 * n; i < x; i++){
		if (i % 2 == 0)
			a[1][(i - 2 * n)/2] = cur++;
		else
			a[2][(i - 2 * n)/2] = cur++;
	}

	for (int i = 0; i < n; i++){
		if (a[1][i])	cout << a[1][i] << " ";
		if (a[0][i])	cout << a[0][i] << " ";
		if (a[2][i])	cout << a[2][i] << " ";
		if (a[3][i])	cout << a[3][i] << " ";
	}
	cout << "\n";
	return	0;
}