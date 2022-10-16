#include <iostream>

using namespace std;

int main()
{
	int l, r, a, ans = 0;
	cin >> l >> r >> a;
	int d = min(l, r);
	l -= d;
	r -= d;
	ans += 2 * d;
	l += r;
	d = min(l, a);
	l -= d;
	a -= d;
	ans += d*2;
	if(l == 0) ans += a/2*2;
	cout << ans << endl;
}