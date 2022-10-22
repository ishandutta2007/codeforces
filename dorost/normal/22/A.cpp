/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 192;
int a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	for (int i = 0; i < n; i++)
		if (a[i] > a[0])
			return cout << a[i], 0;
	cout << "NO";
}