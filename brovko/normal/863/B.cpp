#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n *= 2;
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);

    int Min = 1e9;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
    {
        int x = 0;
        for(int k=0; k<n; k++)
        {
            while(k == i || k == j)
                k++;
            if(k < n)
            {
                x -= a[k];
                k++;
                while(k == i || k == j)
                    k++;
                x += a[k];
            }
        }

        Min = min(Min, x);
    }

    cout << Min;
}