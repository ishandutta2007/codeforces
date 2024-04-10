#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, x, y, z, p;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> z >> p;

    x %= 4;
    y %= 2;
    z %= 4;
    
    int N = n, M = m;

    for(int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        
        n = N, m = M;

        for(int j = 0; j < x; j++)
        {
            swap(a, b);
            b = n + 1 - b;
            swap(n, m);
        }

        for(int j = 0; j < y; j++)
            b = m + 1 - b;

        for(int j = 0; j < z; j++)
        {
            swap(a, b);
            a = m + 1 - a;
            swap(n, m);
        }

        cout << a << ' ' << b << "\n";
    }
}