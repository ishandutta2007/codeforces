#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[1505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int k=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            if(a[i] < a[j])
                k^=1;

    int m;
    cin >> m;
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        int x = r - l + 1;

        if(x * (x - 1) / 2 % 2)
            k ^= 1;
        if(k)
            cout << "odd\n";
        else cout << "even\n";
    }
}