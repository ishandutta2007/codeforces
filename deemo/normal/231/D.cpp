#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a[10];

int main(){
	int xx, yy, zz;	cin >> xx >> yy >> zz;
	int x, y, z;	cin >> x >> y >> z;
	for (int i = 0; i < 6; i++)	cin >> a[i];

	int ans = 0;
	if (xx < 0)	ans += a[4];
	if (xx > x)	ans += a[5];
	if (yy < 0)	ans += a[0];
	if (yy > y)	ans += a[1];
	if (zz < 0)	ans += a[2];
	if (zz > z)	ans += a[3];
	cout << ans << endl;
	return 0;
}