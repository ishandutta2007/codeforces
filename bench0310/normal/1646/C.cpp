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
        ll n;
        cin >> n;
        vector<ll> f;
        ll p=2;
        for(int i=3;i<=14;i++)
        {
            p*=i;
            f.push_back(p);
        }
        int res=100;
        for(int m=0;m<(1<<12);m++)
        {
            ll s=0;
            for(int i=0;i<12;i++) if(m&(1<<i)) s+=f[i];
            if(s<=n) res=min(res,popcount(uint32_t(m))+popcount(uint64_t(n-s)));
        }
        cout << res << "\n";
    }
    return 0;
}