#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            int x;
            cin >> x;

            if(x)
            {
                cout << abs(i - 2) + abs(j - 2);
                return 0;
            }
        }
}