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
        vector<int> a(n,0);
        for(int &x:a) cin >> x;
        vector<bool> pr(n+1,1);
        for(int i=2;i*i<=n;i++)
        {
            if(!pr[i]) continue;
            for(int j=i*i;j<=n;j+=i) pr[j]=0;
        }
        vector<int> d;
        for(int i=2;i<=n;i++) if(pr[i]&&(n%i)==0) d.push_back(n/i);
        int m=d.size();
        multiset<ll> s[m];
        vector<vector<ll>> v(m);
        for(int i=0;i<m;i++)
        {
            v[i].assign(d[i],0);
            for(int j=0;j<n;j++) v[i][j%d[i]]+=a[j];
            for(int j=0;j<d[i];j++) s[i].insert(v[i][j]);
        }
        auto solve=[&]()
        {
            ll res=0;
            for(int i=0;i<m;i++) res=max(res,(*s[i].rbegin())*d[i]);
            cout << res << "\n";
        };
        solve();
        while(q--)
        {
            int p,x;
            cin >> p >> x;
            p--;
            for(int i=0;i<m;i++)
            {
                s[i].erase(s[i].find(v[i][p%d[i]]));
                v[i][p%d[i]]+=(x-a[p]);
                s[i].insert(v[i][p%d[i]]);
            }
            a[p]=x;
            solve();
        }
    }
    return 0;
}