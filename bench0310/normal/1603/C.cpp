#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int mod=998244353;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto mul=[&](int a,int b)->int{return (ll(a)*b)%mod;};
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<array<int,2>> v;
        int res=0;
        for(int i=n;i>=1;i--)
        {
            vector<array<int,2>> u;
            auto ins=[&](int nx,int c)
            {
                if(!u.empty()&&u.back()[0]==nx) u.back()[1]=add(u.back()[1],c);
                else u.push_back({nx,c});
            };
            int x=a[i];
            for(auto [y,c]:v)
            {
                int m=((x+y-1)/y);
                res=add(res,mul(m-1,mul(i,c)));
                ins(x/m,c);
            }
            ins(x,1);
            v=u;
        }
        cout << res << "\n";
    }
    return 0;
}