#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        ll res=0;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            res-=((i-1)*a[i]-sum);
            sum+=a[i];
        }
        cout << res+a[n] << "\n";
    }
    return 0;
}