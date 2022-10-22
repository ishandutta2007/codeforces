#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int Min=k;
        for(int i=k;i<n;i++)
            if(a[i]-a[i-k]<a[Min]-a[Min-k])
                Min=i;
        cout << (a[Min]+a[Min-k])/2 << "\n";
    }
}