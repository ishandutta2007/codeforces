#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void test(int a, int b) {
	if(a == b) {
		cout << "YES\n";
		exit(0);
	}
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	test(a, b+c+d);
	test(a+b, c+d);
	test(a+c, b+d);
	test(a+d, b+c);
	test(a+b+c, d);
	test(a+b+d, c);
	test(a+c+d, b);
	cout << "NO\n";
}