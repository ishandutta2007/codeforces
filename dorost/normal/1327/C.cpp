#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	cout << 2 * n * m - 2 << endl; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 1; j++){
			cout << (i % 2 == 0 ? "R" : "L");
		}
		cout << (i != n - 1 ? "D" : "");
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 1; j++){
			cout << (i % 2 ? "R" : "L");
		}
		cout << (i != n - 1 ? "U" : "");
	}
}