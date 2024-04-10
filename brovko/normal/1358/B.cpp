#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int t, n, a[100005];

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
        sort(a, a+n);

        int i=n-1;
        while(i>=0 && a[i]-i>1)
            i--;
        cout << i+2 << "\n";
    }
}