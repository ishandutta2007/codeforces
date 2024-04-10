#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    int x=0;

    for(int i=0;i<n;i++)
        if(k)
        {
            if(a[i]>x)
            {
                cout << a[i]-x << "\n";
                x=a[i];
                k--;
            }

            if(i==n-1)
                while(k)
                {
                    k--;
                    cout << 0 << "\n";
                }
        }
}