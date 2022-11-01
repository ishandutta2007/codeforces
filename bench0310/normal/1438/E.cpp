#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<ll> sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int res=0;
    auto ch=[&](int l,int r)
    {
        if(l+2<=r&&(a[l]^a[r])==sum[r-1]-sum[l]) res++;
    };
    multiset<array<ll,2>> s;
    for(int i=n;i>=1;i--)
    {
        auto it=s.begin();
        while(it!=s.end()&&(*it)[0]<=a[i]+sum[i])
        {
            ch(i,(*it)[1]);
            it++;
        }
        s.insert({-a[i]+sum[i-1],i});
    }
    cout << res << "\n";
    return 0;
}