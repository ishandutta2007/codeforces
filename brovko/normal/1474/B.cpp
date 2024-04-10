#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int t, d, np[1000005], rp[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i * i < 1000005; i++)
        if(np[i] == 0)
            for(int j = i * i; j < 1000005; j += i)
                np[j] = 1;

    int x = 1000000000;

    for(int i = 1000004; i >= 0; i--)
    {
        if(np[i] == 0)
            x = i;

        rp[i] = x;
    }

    cin >> t;

    while(t--)
    {
        cin >> d;

        int p = rp[d + 1];
        int q = rp[d + p];

        cout << p * q << "\n";
    }
}