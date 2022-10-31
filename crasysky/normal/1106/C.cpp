#include <iostream>
#include <algorithm>
using namespace std;
int a[1000006];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long ans = 0;
	for (int i = 1; i <= n / 2; ++ i)
		ans += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
	cout <<ans << endl;
}