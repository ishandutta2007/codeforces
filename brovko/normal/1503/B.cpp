#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, x[2], y[2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    x[0] = 0, y[0] = 0, x[1] = 0, y[1] = 1;

    for(int i = 0; i < n * n; i++)
    {
        int a;
        cin >> a;

        if(a != 1 && x[0] < n)
        {
            cout << 1 << ' ' << x[0] + 1 << ' ' << y[0] + 1 << endl;

            y[0] += 2;

            if(y[0] >= n)
            {
                x[0]++;
                y[0] = x[0] % 2;
            }
        }
        else if(a != 2 && x[1] < n)
        {
            cout << 2 << ' ' << x[1] + 1 << ' ' << y[1] + 1 << endl;

            y[1] += 2;

            if(y[1] >= n)
            {
                x[1]++;
                y[1] = (x[1] + 1) % 2;
            }
        }
        else if(x[1] < n)
        {
            cout << 3 << ' ' << x[1] + 1 << ' ' << y[1] + 1 << endl;

            y[1] += 2;

            if(y[1] >= n)
            {
                x[1]++;
                y[1] = (x[1] + 1) % 2;
            }
        }
        else
        {
            cout << 3 << ' ' << x[0] + 1 << ' ' << y[0] + 1 << endl;

            y[0] += 2;

            if(y[0] >= n)
            {
                x[0]++;
                y[0] = x[0] % 2;
            }
        }
    }
}