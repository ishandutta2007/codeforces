#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int k, n, w;
	cin >> k >> n >> w;
	int ans = max(k * (w * (w + 1) / 2) - n, 0);
 
	cout << ans;
	return 0;
}