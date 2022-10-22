#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k;
char a[2005][2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    int ans=0;

    for(int i=0; i<n; i++)
    {
        int x=0;
        for(int j=0; j<m; j++)
        {
            if(a[i][j]=='.')
                x++;
            else x=0;

            if(x>=k)
                ans++;
        }
    }

    for(int j=0; j<m; j++)
    {
        int x=0;
        for(int i=0; i<n; i++)
        {
            if(a[i][j]=='.')
                x++;
            else x=0;

            if(x>=k)
                ans++;
        }
    }
    
    if(k==1)
        ans/=2;
    
    cout << ans;
}