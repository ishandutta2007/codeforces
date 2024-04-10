#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k;
char c[100005];

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
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> c[i];
        sort(c, c+n);
        if(c[0]==c[n-1])
            for(int i=0;i<(n+k-1)/k;i++)
                cout << c[0];
        else
        {
            if(c[0]!=c[k-1])
                cout << c[k-1];
            else
            {
                cout << c[0];
                if(c[k]!=c[n-1])
                    for(int i=k;i<n;i++)
                        cout << c[i];
                else
                    for(int i=k;i<n;i+=k)
                    cout << c[i];
            }
        }
        cout << "\n";
    }
}