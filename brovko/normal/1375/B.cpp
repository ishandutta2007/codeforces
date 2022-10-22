#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, m, a[305][305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    
    while(t--)
    {
        cin >> n >> m;
        int f = 1;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                
                int x = 4;
                
                if(i == 0 || i == n - 1)
                    x--;
                
                if(j == 0 || j == m - 1)
                    x--;
                
                if(a[i][j] > x)
                    f = 0;
                else a[i][j] = x;
            }
            
        if(f == 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    cout << a[i][j] << ' ';
                    
                cout << "\n";
            }
        }
    }
}