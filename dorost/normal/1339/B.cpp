#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		for (int i = (n - 1) / 2; i >= 0; i--){
			if (n % 2 && i == n / 2){
				cout << a[i] << ' ';
				continue;
			}
			cout << a[n - 1 - i] << ' ' << a[i] << ' ';
		}
		cout << endl;
	}
}