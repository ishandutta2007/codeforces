/* 	* In the name of GOD 
	* Thanks God */
// #div3_should_be_easier
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 53;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--)  {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		bool f = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] - a[i] > 1)
				f = false;
		}
		cout << (f ? "yEs" : "nO");
		cout << '\n'; // :|
	}
}