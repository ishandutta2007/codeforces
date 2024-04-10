#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 oidhfdoif

using namespace std;

int t, n, m, x, y;
char a[1005][1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        int k=0;
        cin >> n >> m >> x >> y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    cin >> a[i][j];
                    if(a[i][j]=='.')
                        k++;
                }
        if(2*x<=y)
        {
            cout << k*x << endl;
        }
        else
        {
            int c=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(a[i][j]=='.')
            {
                if(j!=m-1 && a[i][j+1]=='.')
                {
                    c+=y;
                    a[i][j]='#';
                    a[i][j+1]='#';
                }
                else
                {
                    c+=x;
                    a[i][j]='#';
                }
            }
            cout << c << endl;
        }
    }
}