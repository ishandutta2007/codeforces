#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n / 2; j++){
			a[i][j] = i * n / 2 + j + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < n / 2; j++){
			a[i][j + n / 2] = n * n - i * n / 2 + j + 1 - n / 2;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}