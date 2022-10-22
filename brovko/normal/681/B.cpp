#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i * 1234567 <= n; i++)
        for(int j = 0; i * 1234567 + j * 123456 <= n; j++)
    {
        if((n - i * 1234567 - j * 123456) % 1234 == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}