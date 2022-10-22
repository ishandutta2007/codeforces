#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n==1)
    {
        cout << a[0];
        return 0;
    }
    sort(a, a+n);
    if(a[n-1]<0)
    {
        for(int i=0;i<n;i++)
            a[i]=-a[i];
        sort(a, a+n);
    }

    int s=0;
    for(int i=0;i<n;i++)
        s+=abs(a[i]);
    if(a[0]>0)
        cout << s-2*a[0];
    else cout << s;
}