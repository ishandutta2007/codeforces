#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> b(n+2,0);
    for(int i=1;i<=n;i++) cin >> b[i];
    ranges::reverse(b);
    vector<ll> cnt(n+1,0);
    ll now=0;
    ll c=0;
    ll res=0;
    ll m=0;
    for(int i=1;i<=n;i++)
    {
        if(i+k-1<=n)
        {
            ll t=max(ll(0),(b[i]-now+k-1)/k);
            res+=t;
            now+=t*k;
            c+=t;
            if(i+k<=n) cnt[i+k]+=t;
        }
        else m=max({m,ll(0),(b[i]-now+(n+1-i)-1)/(n+1-i)});
        c-=cnt[i];
        now-=c;
    }
    cout << res+m << "\n";
    return 0;
}