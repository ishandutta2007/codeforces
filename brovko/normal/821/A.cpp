#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != 1)
                {
                    int f = 0;
                    for(int s = 0; s < n; s++)
                        for(int t = 0; t < n; t++)
                            if(a[i][j] == a[i][s] + a[t][j])
                                f = 1;

                    if(f == 0)
                    {
                        cout << "No";
                        return 0;
                    }
                }

    cout << "Yes";
}