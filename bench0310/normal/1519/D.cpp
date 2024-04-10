#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+2,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<ll> suml(n+1,0);
    for(int i=1;i<=n;i++) suml[i]=(suml[i-1]+a[i]*b[i]);
    vector<ll> sumr(n+2,0);
    for(int i=n;i>=1;i--) sumr[i]=(sumr[i+1]+a[i]*b[i]);
    reverse(a.begin(),a.end());
    ll res=suml[n];
    for(int s=1-n;s<=n-1;s++)
    {
        vector<ll> now(n+1,0);
        for(int i=1;i<=n;i++)
        {
            now[i]=now[i-1];
            if(1<=i-s&&i-s<=n) now[i]+=(b[i]*a[i-s]);
        }
        int sum=(s+n+1);
        for(int i=1;i<=n;i++)
        {
            int j=(sum-i);
            if(!(i<=j&&j<=n)) continue;
            res=max(res,suml[i-1]+sumr[j+1]+now[j]-now[i-1]);
        }
    }
    cout << res << "\n";
    return 0;
}