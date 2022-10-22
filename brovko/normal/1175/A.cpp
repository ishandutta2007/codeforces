#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int x=n%k;
        n-=n%k;
        while(n)
        {
            x++;
            n/=k;
            x+=n%k;
            n-=n%k;
        }
        cout << x << "\n";
    }
}