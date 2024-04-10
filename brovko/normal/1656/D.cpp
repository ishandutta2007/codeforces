#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int f(int n)
{
    int m = n;

    if((n & n - 1) == 0)
        return -1;

    int k = 2;

    while(n % 2 == 0)
    {
        n /= 2;
        k *= 2;
    }

    k = min(k, 2 * m / k);

    if(k * (k + 1) / 2 > m)
    {
        for(int i = 2; ; i++)
            if(k % i == 0)
            {
                if(i * (i + 1) / 2 <= m)
                    return i;
                else return -1;
            }
    }

    return k;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << f(n) << "\n";
    }
}