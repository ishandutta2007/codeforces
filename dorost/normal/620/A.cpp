#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(abs(a - c), abs(b - d));
}