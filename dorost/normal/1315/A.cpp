#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a --;
		b --;
		cout << max(max(a - x, x) * (b + 1), max(b - y, y) * (a + 1)) << endl;  
	}
}