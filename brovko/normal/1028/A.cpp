#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;
char a[205][205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]=='B')
    {
        int k=0;
        int c=j;
        while(c<m && a[i][c]=='B')
        {
            c++;
            k++;
        }

        cout << i+k/2+1 << ' ' << j+k/2+1;
        return 0;
    }
}