#include <bits/stdc++.h>

using namespace std;

bool a[700];

int main()
{
	int n, tmp, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> tmp;
		a[tmp] = 1;
	}
	for(int i=1;i<700;i++)
		ans += a[i];
	cout << ans << endl;
}