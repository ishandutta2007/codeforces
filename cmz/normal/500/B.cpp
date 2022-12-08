#include<bits/stdc++.h>
using namespace std;
const int N = 300 + 10;
const int MOD = 1e9 + 7;
int n;
int a[N];
char b[N][N];
int main() {
	cin >> n;
	for(int i = 0; i < n; ++ i)  cin >> a[i];
	for(int i = 0; i < n; ++ i) {
		scanf("%s", b[i]);
		for(int j = 0; j < n; ++ j) {
			b[i][j] -= '0';
		}
		b[i][i] = 1;
	}
	for(int k = 0; k < n; ++ k) {
		for(int i = 0; i < n; ++ i) {
			for(int j = 0; j < n; ++ j) {
				b[i][j] |= b[i][k] && b[k][j];
			}
		}
	}
	for(int i = 0; i < n; ++ i) {
		int c = n, tmp = n + 1;
		for(int j = i; j < n; ++ j) {
			if (b[i][j] && a[j] < tmp) {
				tmp = a[j];
				c = j;
			}
		}
		swap(a[i], a[c]);
	}
	for(int i = 0; i < n; ++ i)  cout << a[i] << ' ';
	cout << endl;
	return 0;
}