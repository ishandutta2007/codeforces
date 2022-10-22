/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int ma = *max_element(a, a + n);
	int mna = *min_element(a, a + n) * 2;
	int mb = *min_element(b, b + m);
	if (max(ma, mna) < mb)
		cout << max(ma, mna);
	else
		cout << -1;
}