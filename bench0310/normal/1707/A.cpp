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
        vector<int> a(n+1,0);
        vector<int> u;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i]>q) u.push_back(i);
        }
        int sz=u.size();
        int l=0,r=sz+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            int p=(sz-m);
            bool ok=1;
            int x=q;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<=q||(p<sz&&i==u[p]))
                {
                    ok&=(x>0);
                    x-=(x<a[i]);
                    if(p<sz&&i==u[p]) p++;
                }
            }
            if(ok) l=m;
            else r=m;
        }
        string res(n+1,'0');
        for(int i=1;i<=n;i++) if(a[i]<=q) res[i]='1';
        for(int i=1;i<=l;i++) res[u[sz-i]]='1';
        cout << res.substr(1,n) << "\n";
    }
    return 0;
}