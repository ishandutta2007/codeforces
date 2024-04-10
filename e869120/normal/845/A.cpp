#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
int a[1000], n;
int main() {
	cin >> n; n *= 2; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	if (a[n / 2 - 1] != a[n / 2])cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}