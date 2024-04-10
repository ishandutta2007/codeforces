#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, b[200005], c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int x = 0;

    while(n)
    {
        b[x + 100000] = n % 2;
        c[x + 100000] = n % 2;
        k -= n%2;
        x++;
        n /= 2;
    }

    if(k < 0)
    {
        cout << "No";
        return 0;
    }

    int p=k;

    for(int i=200000; i>=0; i--)
    {
        while(b[i] > 0 && k > 0)
        {
            b[i]--;
            b[i - 1] += 2;
            k--;
        }
    }

    int Max=-1e9;

    for(int i=200000; i>=0; i--)
        if(b[i])
            Max = max(Max, i);

    for(int i=200000; i>Max; i--)
    {
        while(c[i] > 0 && p > 0)
        {
            c[i]--;
            c[i - 1]+=2;
            p--;
        }
    }

    int Min = 0;
    while(c[Min] == 0)
        Min++;

    while(p)
    {
        p--;
        c[Min]--;
        c[Min - 1] += 2;
        Min--;
    }

    cout << "Yes\n";
    for(int i=200000; i>=0; i--)
    {
        while(c[i]--)
            cout << i-100000 << ' ';
    }
}