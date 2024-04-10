#include <iostream>
#include <bitset>

using namespace std;

bitset<1009487> x, y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, ans = 0, tmp;
	cin >> a >> b;
	for(int su = 0, i=0;i<a;i++) cin >> tmp, su += tmp, x[su] = true;
	for(int su = 0, i=0;i<b;i++) cin >> tmp, su += tmp, y[su] = true;
	cout << (x & y).count() << endl;
}