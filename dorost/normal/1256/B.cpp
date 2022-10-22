#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		bool u[n] = {};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = n - 1; j > i; j--){
				if (u[j] == 0 && a[j] < a[j - 1])
					swap(a[j], a[j - 1]), u[j] = true;
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
}