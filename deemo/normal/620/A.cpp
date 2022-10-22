#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a, b, c, d;	cin >> a >> b >> c >> d;

	int e = abs(a-c), f = abs(b - d);

	int ans = min(e, f);
	int z = min(e, f);
	e -= z;
	f -= z;
	ans += max(e, f);
	cout << ans << endl;
	return	0;
}