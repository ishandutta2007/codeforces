#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, ans = 0;
	cin >> a >> b;
	int df = abs(a - b), edf = df / 2;
	ans += (1 + edf) * (edf) + (df % 2 ? edf+1 : 0);
	cout << ans << endl;
}