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
        bool ok=1;
        auto go=[&](vector<int> a)
        {
            vector<ll> sum(n+1,0);
            for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
            stack<array<ll,2>> s;
            a[n+1]=(1<<30);
            s.push({n+1,0});
            for(int i=n;i>=1;i--)
            {
                ll m=-(1ll<<60);
                while(a[s.top()[0]]<=a[i])
                {
                    m=max(m,s.top()[1]);
                    s.pop();
                }
                ok&=(m-sum[i]<=0);
                s.push({i,max(m,sum[i])});
            }
        };
        vector<int> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        go(a);
        ranges::reverse(a);
        go(a);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}