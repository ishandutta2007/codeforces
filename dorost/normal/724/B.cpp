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
	bool f = false;
	int a[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for (int c1 = 0; c1 < m; c1++){
		for (int c2 = 0; c2 < m; c2++){
			for (int i = 0; i < n; i++){
				swap(a[i][c1], a[i][c2]);
			}
			bool h = true;
			for (int i = 0; i < n; i++){
				int an = 0;
				for (int j = 0; j < m; j++){
					if (a[i][j] != j + 1)
						an++;
				}
				if (an > 2)
					h = false;
			}
			if (h)
				f = true;
			for (int i = 0; i < n; i++){
				swap(a[i][c1], a[i][c2]);
			}
		}
	}
	cout << (f ? "YES" : "NO");
}