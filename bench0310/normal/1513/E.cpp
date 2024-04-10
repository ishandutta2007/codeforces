#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const ll mod=1000000007;
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
    auto c=[&](int a,int b)->ll{return mul(f[a],mul(finv[b],finv[a-b]));};
    auto opt=[&](vector<int> v)->ll
    {
        int m=v.size();
        ll res=f[m];
        sort(v.begin(),v.end());
        int l=0;
        while(l<m)
        {
            int r=l;
            while(r+1<m&&v[r+1]==v[l]) r++;
            res=mul(res,finv[r-l+1]);
            l=r+1;
        }
        return res;
    };
    vector<int> a(n,0);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    vector<int> one,two;
    int mid=0;
    if(sum%n)
    {
        cout << "0\n";
        exit(0);
    }
    ll good=(sum/n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<good) one.push_back(a[i]);
        else if(a[i]>good) two.push_back(a[i]);
        else mid++;
    }
    if(one.size()<2||two.size()<2) cout << opt(a) << "\n";
    else
    {
        ll res=mul(mul(opt(one),opt(two)),mul(2,c(n,mid)));
        cout << res << "\n";
    }
    return 0;
}