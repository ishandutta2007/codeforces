#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long ans = 0;
	long long cur = 1;
    while (cur <= n)
    {
        long long x = min(n / cur, 9ll);
        ans += x;
        n -= x * cur;
        cur *= 10;
    }
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    cout << ans << endl;
	return 0;
}