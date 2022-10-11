#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
using namespace std;
int d, r, n, cnt;
int main() {
	cin >> r >> d >> n; d = r - d;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		int Y = a*a + b*b;
		if ((d + c)*(d + c) <= Y && Y <= (r - c)*(r - c))cnt++;
	}
	cout << cnt << endl;
	return 0;
}