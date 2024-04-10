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
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        int res=0;
        bool ok=1;
        auto go=[&](auto &&self,int l,int r)->void
        {
            if(l==r) return;
            int sz=(r-l+1);
            int m=(l+r)/2;
            int c=0;
            for(int i=l;i<=m;i++) c+=(p[i]<=m);
            if(c==0)
            {
                for(int i=l;i<=m;i++) swap(p[i],p[i+sz/2]);
                res++;
            }
            ok&=(c==0||c==sz/2);
            self(self,l,m);
            self(self,m+1,r);
        };
        go(go,1,n);
        if(ok) cout << res << "\n";
        else cout << "-1\n";
    }
    return 0;
}