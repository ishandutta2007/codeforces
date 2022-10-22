#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, n, a[100005], b[100005], l, r, f;

int32_t main()
{
    cin >> t;
    while(t--)
    {
        f=0;
        l=-1;
        r=-1;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];
        for(int i=0;i<n;i++)
            if(a[i]!=b[i])
            {
                if(l==-1)
                    l=i;
                r=i;
            }
        l=max(l, 0ll);
        r=max(r, 0ll);
        int d=b[l]-a[l];
        for(int i=l+1;i<=r;i++)
        {
            if(b[i]-a[i]!=d && f==0)
            {
                cout << "NO";
                f=1;
            }
        }
        if(f==0)
            if(d>=0)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}