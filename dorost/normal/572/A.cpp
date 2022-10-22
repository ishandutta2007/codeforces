#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, m, k, h;
	cin >> n >> m >> k >> h;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cout << (a[k - 1] < b[m - h] ? "YES" : "NO"); 
}