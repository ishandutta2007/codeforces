#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int n, m, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans=0;
    sort(a, a+n);
    for(int i=n-1;i>=1;i--)
    {
        if(a[i-1]>=a[i])
        {
            if(a[i]>1)
            {
                ans+=a[i-1];
                a[i-1]=a[i]-1;
            }
            else
            {
                ans+=a[i-1]-1;
                a[i-1]=1;
            }
        }
        else
        {
            ans+=a[i-1];
        }
    }
    cout << ans;
}