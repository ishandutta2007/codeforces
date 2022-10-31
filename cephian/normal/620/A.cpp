#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	ll x1,x2,y1,y2;
	cin >>x1>>y1>>x2>>y2;
	cout << max(abs(x1-x2), abs(y1-y2)) << "\n";

	return 0;
}