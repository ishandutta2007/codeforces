/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10000;
int a[N], an[N];

int32_t main(){
	int d = 1;
	a[0] = d;
	for (int i = 1; i < N; i++){
		a[i] = (a[i - 1] + i + 1);
	}
	an[0]  =1;
	for (int i = 1; i < N; i++){
		an[i] = an[i - 1] + a[i];
	}
	for (int i = 0; i < 10; i++)
		cerr << an[i] << ' ';
	int n;
	cin >> n;
	for (int i = 0; i < N; i++){
		if (an[i] > n)
			return cout << i, 0;
	}
}