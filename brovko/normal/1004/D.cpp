#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, A[1000005], k[1000005];

int f(int x)
{
    if(x == 0)
        return 1;

    return 4 * x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> A[i];

    sort(A, A + n);

    for(int i = 0; i < n; i++)
        k[A[i]]++;

    int x = 0;

    while(k[x] == f(x))
        x++;

    x--;

    if(x < 0)
    {
        cout << -1;
        return 0;
    }

    int a = x, bc = A[n - 1];

    for(int b = 0; b <= bc; b++)
    {
        if(n % (a + b + 1) == 0)
        {
            int cd = n / (a + b + 1) - 1;
            int c = bc - b;
            int d = cd - c;

            if(a < 0 || b < 0 || c < 0 || d < 0)
                continue;

            int k1[n];

            for(int i = 0; i < n; i++)
                k1[i] = 0;

            for(int i = 0; i < a + b + 1; i++)
                for(int j = 0; j < c + d + 1; j++)
                    k1[abs(i - a) + abs(j - d)]++;

            int F = 1;

            for(int i = 0; i < n; i++)
                if(k1[i] != k[i])
                    F = 0;

            if(F)
            {
                cout << a + b + 1 << ' ' << c + d + 1 << "\n" << a + 1 << ' ' << d + 1;
                return 0;
            }
        }
    }

    cout << -1;
}