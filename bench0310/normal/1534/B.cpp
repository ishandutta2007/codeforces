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
        vector<int> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i-1]<a[i]&&a[i]>a[i+1])
            {
                ll x=a[i]-max(a[i-1],a[i+1]);
                res+=x;
                a[i]-=x;
            }
        }
        for(int i=0;i<=n;i++) res+=abs(a[i]-a[i+1]);
        cout << res << "\n";
    }
    return 0;
}