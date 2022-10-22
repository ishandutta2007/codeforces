/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		a[n] = 0;
		vector <int> v = {a[0]};
		for (int i = 1; i < n - 1; i++){
			if (a[i] > a[i + 1] != a[i - 1] > a[i])
				v.push_back(a[i]);
		}
		v.push_back(a[n - 1]);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}