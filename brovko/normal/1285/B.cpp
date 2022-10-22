#include <bits/stdc++.h>
#define int long long


using namespace std;

int t, n, a[100005], s[100005], Max, s1;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        Max=0;
        for(int i=0;i<n;i++)
            {
                cin >> a[i];
                if(i!=n-1)
                {
                    if(i==0)
                        s[i]=a[i];
                        else s[i]=a[i]+max(0ll, s[i-1]);
                    Max=max(Max, s[i]);
                }

            }
        int x=0;
        for(int i=n-1;i>0;i--)
        {
            x+=a[i];
            Max=max(x, Max);
        }
        s1=0;
        for(int i=0;i<n;i++)
            s1+=a[i];
        if(s1>Max)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}