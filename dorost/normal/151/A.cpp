#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int a[8];
	for (int i = 0; i < 8; i++)
		cin >> a[i];
	cout << min({a[1] * a[2] / a[6], a[3] * a[4], a[5] / a[7]}) / a[0];
}