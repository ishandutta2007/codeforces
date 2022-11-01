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
        int n,s;
        cin >> n >> s;
        vector<ll> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        a[n+1]=-(1ll<<60);
        map<ll,int> m;
        m[0]=n+2;
        ll x=0;
        int l=1,r=0;
        for(int i=n+1;i>=1;i--)
        {
            x-=a[i];
            while((*m.rbegin()).first>=x) m.erase(prev(m.end()));
            m[x]=i;
            auto it=m.lower_bound(x-s);
            it--;
            int p=(it->second)-2;
            if(p-i>=r-l) tie(l,r)={i,p};
        }
        if(l<=r) cout << l << " " << r << "\n";
        else cout << "-1\n";
    }
    return 0;
}