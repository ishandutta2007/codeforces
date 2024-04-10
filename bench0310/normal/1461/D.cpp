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
        int n,q;
        cin >> n >> q;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        map<ll,int> m;
        for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) m[a[i]]=i;
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        auto sum=[&](int l,int r)->ll{return (s[r]-s[l-1]);};
        set<ll> opt;
        function<void(int,int)> solve=[&](int l,int r)
        {
            if(l>r) return;
            opt.insert(sum(l,r));
            if(a[l]==a[r]) return;
            ll mid=(a[l]+a[r])/2;
            auto it=m.upper_bound(mid);
            assert(it!=m.end());
            int x=(it->second);
            solve(l,x-1);
            solve(x,r);
        };
        solve(1,n);
        while(q--)
        {
            ll b;
            cin >> b;
            if(opt.find(b)!=opt.end()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}