#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[105], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        while(x--)
        {
            int y;
            cin >> y;
            a[y]++;

            if(a[y] == 1)
                ans++;
        }
    }

    if(ans == m)
        cout << "YES";
    else cout << "NO";
}