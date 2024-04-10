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
	bool f[n] = {};
	for (int i = 0; i < n; i++)
		cin >> a[i], f[i] = true;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int h = 0, i = 0;
	for (i = 0; i < m; i++){
		int j;
		for (j = h; j < n; j++){
			if (a[j] <= b[i]){
				break;
			}
		}
		h = j + 1;
	//	cout << i << ":" << h <<endl;
		if (h == n + 1){
			break;
		}
	}
	cout << i;
}