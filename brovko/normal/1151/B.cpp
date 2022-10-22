#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    int x=0;
    for(int i=0;i<n;i++)
        x^=a[i][0];

    if(x)
    {
        cout << "TAK\n";
        for(int i=0;i<n;i++)
            cout << "1 ";
        return 0;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(a[i][j]!=a[i][0])
        {
            cout << "TAK\n";
            for(int k=0;k<n;k++)
            {
                if(k==i)
                    cout << j+1 << ' ';
                else cout << "1 ";
            }
            return 0;
        }
    }

    cout << "NIE";
}