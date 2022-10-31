#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
bool vis[1000006];
int a[1003];
int gcd(int x, int y){
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int _rand(){
	int sum = 0;
	for (int i = 0; i <= 30; ++ i)
		sum += (rand() & 1) << i;
	return sum;
}
int main(){
	srand(time(0));
	int n;
	cin >> n;
	int l = 0, r = 1000000000, mx, used = 0;
	while (l <= r){
		int m = l + r >> 1;
		cout << "> " << m << endl;
		cout.flush();
		++ used;
		int flag;
		cin >> flag;
		if (flag == 0){
			mx = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	for (int i = 1; i <= min(60 - used, n); ++ i){
		int x = _rand() % n + 1;
		while (vis[x])
			x = _rand() % n + 1;
		vis[x] = true;
		cout << "? " << x << endl;
		cout.flush();
		cin >> a[i];
	}
	a[min(60 - used, n) + 1] = mx;
	int m = min(60  - used, n) + 1;
	sort(a + 1, a + 1 + m);
	int d = 0;
	for (int i = 2; i <= m; ++ i)
		d = gcd(d, a[i] - a[i - 1]);
	cout << "! " << mx - (n - 1) * d << " " << d << endl;
}