#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll inf=(1ll<<60);
    int n,m;
    cin >> n >> m;
    ll x,k,y;
    cin >> x >> k >> y;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b(m+1,0);
    for(int i=1;i<=m;i++) cin >> b[i];
    auto out=[](){cout << "-1\n";exit(0);};
    auto solve=[&](int l,int r)->ll
    {
        int sz=r-l+1;
        int one=0;
        if(l-1>=1) one=max(one,a[l-1]);
        if(r+1<=n) one=max(one,a[r+1]);
        int two=0;
        for(int i=l;i<=r;i++) two=max(two,a[i]);
        ll res=inf;
        if(one>two) res=y*sz;
        for(ll i=1;i*k<=sz;i++) res=min(res,i*x+(sz-i*k)*y);
        if(res==inf) out();
        return res;
    };
    int l=0;
    int r=1;
    ll res=0;
    for(int i=1;i<=m;i++)
    {
        while(r<=n&&a[r]!=b[i]) r++;
        if(r==n+1) out();
        res+=solve(l+1,r-1);
        l=r;
    }
    if(l+1<=n) res+=solve(l+1,n);
    cout << res << "\n";
    return 0;
}