/*	* In the name of GOD
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 33;
vector <int> a, b;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		a.clear();
		b.clear();
		int x;
		for (int i = 0; i < n; i++){
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < n; i++){
			cin >> x;
			b.push_back(x);
		}
		int sum = 0;
		sort (a.begin(), a.end());
		sort (b.begin(), b.end());
		reverse (b.begin(), b.end());
		for (int i = n - 1; i >= k; i--){
			sum += a[i];
			a.pop_back();
		}
		for (int i = 0; i < k; i++){
			a.push_back(b[i]);
		}
		sort(a.begin(), a.end());
		reverse (a.begin(), a.end());
		for (int i = 0; i < k; i++){
			sum += a[i];
		}
		cout << sum << endl;
	}
}