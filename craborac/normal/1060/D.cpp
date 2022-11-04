#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long a[(int)1e5 + 10], b[(int)1e5 + 10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(a[i], b[i]);
    }
    cout << ans + n << endl;
	return 0;
}