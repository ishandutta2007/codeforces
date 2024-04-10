/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int x = a + b + c + d + e;
    if (x % 5 || x == 0)
        cout << -1;
    else
        cout << x / 5;
}