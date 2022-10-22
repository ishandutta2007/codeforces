#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, m, a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> a[i][j];

        int kx = 0;
        int ky = 0;

        for(int i=0; i<n; i++)
        {
            int f = 1;
            for(int j=0; j<m; j++)
                if(a[i][j] == 1)
                    f = 0;

            if(f == 1)
                kx++;
        }

        for(int j=0; j<m; j++)
        {
            int f = 1;
            for(int i=0; i<n; i++)
                if(a[i][j] == 1)
                    f = 0;
            if(f == 1)
                ky++;
        }

        if(min(kx, ky) % 2 == 0)
            cout << "Vivek\n";
        else cout << "Ashish\n";
    }
}