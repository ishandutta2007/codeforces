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
        string s;
        cin >> s;
        int odd=0;
        int two=0;
        int l=0;
        const ll mod=998244353;
        auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
        vector<ll> f(n+1,1);
        vector<ll> inv(n+1,1);
        vector<ll> finv(n+1,1);
        for(int i=2;i<=n;i++)
        {
            f[i]=mul(f[i-1],i);
            inv[i]=mod-mul(mod/i,inv[mod%i]);
            finv[i]=mul(finv[i-1],inv[i]);
        }
        auto c=[&](int a,int b)->ll
        {
            if(a<b||b<0) return 0;
            return mul(f[a],mul(finv[b],finv[a-b]));
        };
        while(l<n)
        {
            if(s[l]=='0')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&s[r+1]=='1') r++;
            odd+=((r-l+1)&1);
            two+=((r-l+1)/2);
            l=r+1;
        }
        cout << c(n-odd-two,two) << "\n";
    }
    return 0;
}