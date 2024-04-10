#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, len;
    cin >> n;

    len = n / 2 + 1;

    cout << len << "\n";
    for (int i = 1; i <= len; i++)
    {
        cout << 1 << " " << i << "\n";
    }
    for (int i = 2; i <= n - len + 1; i++)
    {
        cout << i << " " << len << "\n";
    }


}
/**

**/