#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, x, a[105], b[105], m1, m2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        m1=-1e9;
        m2=-1e9;
        cin >> n >> x;
        for(int i=0;i<n;i++)
        {
            cin >> a[i] >> b[i];
            m1=max(m1, a[i]);
            m2=max(m2, a[i]-b[i]);
        }

     //   cout << m1 << ' ' << m2 << endl;
        if(m2<=0 && x-m1>0)
            cout << -1;
        else if(x-m1<=0)
            cout << 1;
        else cout << 1+(x-m1+m2-1)/m2;
        cout << endl;
    }
}