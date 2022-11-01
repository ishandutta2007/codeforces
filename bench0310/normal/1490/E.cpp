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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> v(a.begin(),a.end());
        sort(v.begin(),v.end());
        vector<ll> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+v[i];
        set<ll> s;
        for(int i=1;i<=n;i++)
        {
            ll now=sum[i];
            int pos=i;
            while(pos<n)
            {
                int l=pos;
                int r=n+1;
                while(l<r-1)
                {
                    int m=(l+r)/2;
                    if(now>=v[m]) l=m;
                    else r=m;
                }
                if(l==pos) break;
                pos=l;
                now=sum[l];
            }
            if(pos==n) s.insert(v[i]);
        }
        vector<int> res;
        for(int i=1;i<=n;i++) if(s.find(a[i])!=s.end()) res.push_back(i);
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}