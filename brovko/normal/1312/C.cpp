#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k, a[35], b[105];

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

        for(int i=0;i<105;i++)
            b[i]=0;

        for(int i=0;i<n;i++)
        {
            int j=0;
            while(a[i])
            {
                b[j]+=a[i]%k;
                j++;
                a[i]/=k;
            }
        }

        int f=0;
        for(int i=0;i<105;i++)
            if(b[i]>1)
                f=1;
        if(f)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}