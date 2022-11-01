#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool ok=1;
    vector<array<ll,2>> h(n);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        s+=a;
        h[i-1]={s,i};
        ok&=(s>=0);
        if(n<=2) ok&=(a>=0);
    }
    ranges::sort(h);
    vector<int> a(n+1,0);
    int x=1;
    for(int i=0;i<n;i++)
    {
        if(i>0&&h[i-1][0]!=h[i][0]) x++;
        a[h[i][1]]=x;
    }
    vector<int> t(n+1,0);
    auto upd=[&](int p,int d)
    {
        for(;p<=n;p=(p|(p+1))) t[p]+=d;
    };
    auto sum=[&](int p)->int
    {
        int b=0;
        for(;p>=1;p=(p&(p+1))-1) b+=t[p];
        return b;
    };
    ok&=(a[n]==x);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=(i-1-sum(a[i]));
        upd(a[i],1);
    }
    if(ok) cout << res << "\n";
    else cout << "-1\n";
    return 0;
}