#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,3>> v(m);
        for(auto &[l,r,x]:v) cin >> l >> r >> x;
        ll two=1;
        for(int i=1;i<=n-1;i++) two=mul(2,two);
        ll res=0;
        for(int b=0;b<30;b++)
        {
            vector<int> d(n+2,0);
            for(auto [l,r,x]:v)
            {
                if((x&(1<<b))==0)
                {
                    d[l]++;
                    d[r+1]--;
                }
            }
            int s=0;
            int c=0;
            for(int i=1;i<=n;i++)
            {
                s+=d[i];
                c+=(s==0);
            }
            if(c>0) res=add(res,mul(1<<b,two));
        }
        cout << res << "\n";
    }
    return 0;
}