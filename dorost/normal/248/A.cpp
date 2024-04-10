#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, x = 0, y = 0, a, b;
	cin >> n;
	int z = n;
	while(n--){
		cin >> a >> b;
		x += a, y += b;
	}
	cout << min({z - max(x, y) + min(x, y), x + y, 2 * z - (x + y)});
}