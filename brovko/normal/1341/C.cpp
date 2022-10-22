#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        int f=1;

        for(int i=0; i<n-1; i++)
            if(!(a[i+1]==a[i]+1 || a[i+1]<a[i]))
                f=0;
        if(f)
            cout << "Yes\n";
        else cout << "No\n";
    }
}