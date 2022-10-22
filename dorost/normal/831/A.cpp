/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 131;
int a[N], s[N];

bool is_strictly_sorted(vector <int> v) {
	if (v.size() == 0)
		return true;
	for (int i = 0; i < v.size() - 1; i++){
		if (v[i] >= v[i + 1])
			return false;
	}
	return true;
}

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1])
			s[i] = 1;
		if (a[i] > a[i + 1])
			s[i] = 2;
		if (a[i] < a[i + 1])
			s[i] = 0;
	}
	cout << (is_sorted(s, s + n - 1) ? "yEs" : "nO");
}