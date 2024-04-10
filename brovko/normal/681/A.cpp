#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a, b;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s >> a >> b;

        if(a >= 2400 && a < b)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}