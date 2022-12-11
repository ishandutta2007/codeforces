#include <iostream>
#include <bitset>


using namespace std;
int n, x, y, p;
long long ans;
bitset<300005> b; 
int main() {
	cin >> n >> x >> y >> b;
	for (int i = 0; i < n; i++)
		if (b[i] == 0 && (i == 0 || b[i - 1] == 1)) p++;
	if (p == 0) ans = 0;
	else if (x < y) ans = 1LL * x * (p - 1) + y;
	else ans = 1LL * y * p;
	printf("%I64d\n", ans);
	return 0;
}