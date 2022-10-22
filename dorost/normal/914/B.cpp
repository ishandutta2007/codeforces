/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], num[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		num[a[i]] ++;
	}
	for (int i = 0; i < N; i++){
		if (num[i] % 2)
			return cout << "Conan", 0;
	}
	cout << "Agasa";
}