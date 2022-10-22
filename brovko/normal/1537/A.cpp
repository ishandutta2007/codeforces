#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int N = 500005;

int t, n, a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        if(s < n)
            cout << "1\n";
        else cout << s - n << "\n";
    }
}