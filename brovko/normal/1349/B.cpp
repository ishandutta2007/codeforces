#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n, k, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int f=0;
        int F=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==k)
                F=1;
        }

        for(int i=0;i<n-1;i++)
            if(a[i]>=k && a[i+1]>=k)
                f=1;
        for(int i=0;i<n-2;i++)
            if(a[i]>=k && a[i+2]>=k)
                f=1;
        if(n==1)
            f=1;

        if(f*F==1)
            cout << "yes\n";
        else cout << "no\n";

    }
}