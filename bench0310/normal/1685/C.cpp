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
        string s;
        cin >> s;
        s="$"+s;
        vector<int> d(2*n+1,0);
        for(int i=1;i<=2*n;i++) d[i]=d[i-1]+(s[i]=='('?1:-1);
        auto mx=[&](int l,int r)->array<int,2> //val,pos
        {
            array<int,2> m={-n-1,0};
            for(int i=l;i<=r;i++) m=max(m,{d[i],i});
            return m;
        };
        vector<array<int,2>> res=[&]()->vector<array<int,2>>
        {
            int l=-1,r=-1;
            for(int i=2*n;i>=1;i--) if(d[i]==-1) l=i-1;
            for(int i=1;i<=2*n;i++) if(d[i]==-1) r=i+1;
            if(l==-1) return {};
            auto [lm,lp]=mx(0,l);
            auto [mm,mp]=mx(l,r);
            auto [rm,rp]=mx(r,2*n);
            if(lm+rm>=mm) return {{lp+1,rp}};
            auto [m,p]=mx(0,2*n);
            return {{1,p},{p+1,2*n}};
        }();
        cout << res.size() << "\n";
        for(auto [l,r]:res) cout << l << " " << r << "\n";
    }
    return 0;
}