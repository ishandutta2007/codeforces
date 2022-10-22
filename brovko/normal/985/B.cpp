#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdifpghig

using namespace std;

int n, m, a[2005][2005], k[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        char c;
        cin >> c;
        a[i][j]=c-'0';
        k[j]+=a[i][j];
    }

    for(int i=0;i<n;i++)
    {
        int f=1;
        for(int j=0;j<m;j++)
            if(a[i][j]==1 && k[j]==1)
                f=0;
        if(f)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}