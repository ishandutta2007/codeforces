/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 123456;
int a[N];

void solve(int s, int e){
	int n = e - s + 1;
	if (n <= 0)
		return;
	if (n % 2)
		a[(s + e) / 2] = (s + e) / 2 + 1;
	if (n != 1){
		a[s] = s + 2;
		a[s + 1] = e + 1;
		a[e] = e;
		a[e - 1] = s + 1;
	}
	solve(s + 2, e - 2);
}

int32_t main(){
	int n;
	cin >> n;
	if (n % 4 > 1){
		return cout << -1, 0;
	}
	solve (0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
}