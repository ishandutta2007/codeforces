#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[105];

bool comp(int i, int j)
{
    return i>j;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a, a+n, comp);
        for(int i=0;i<n;i++)
            cout << a[i] << ' ';
        cout << endl;
    }
}