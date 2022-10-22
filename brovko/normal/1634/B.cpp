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

    int t;
    cin >> t;

    while(t--)
    {

        int n;
        cin >> n;

        int s = 0;

        for(int i = 0; i < n + 2; i++)
        {
            int x;
            cin >> x;

            s += x;
        }

        cout << (s % 2 == 0 ? "Alice" : "Bob");

        cout << "\n";
    }
}