/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1234;
int a[N];
bool is[N];

int32_t main(){
	int n;
	cin >> n;
	is[n] = true;
	for (int i = 0; i < n - 1; i++)
		cin >> a[i], is[i + 1] = true;
	for (int i = 0; i < n - 1; i++){
		is[a[i]] = false;
	}
	for (int i = 1; i <= n; i++){
		if (is[i])
			continue; 
		int ans = 0;
		for (int j = 0; j < n - 1; j++){
			if (a[j] == i && is[j + 2])
				ans ++;
		}
		if (ans < 3)
			return cout << "No", 0;
	}
	cout << "Yes";
}