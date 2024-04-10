/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N], b[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
			cin >> b[i];
		bool f = false;
		int an = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i] == b[j]){
					an = a[i];
					f = true;
				}
			}
		}
		if (!f)
			cout << "No\n";
		else
			cout << "Yes\n1 " << an << endl;
	}
}