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
        int mx=0;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            mx=max(mx,a[i]);
        }
        set<int> s;
        for(int i=1;i<n;i++) s.insert(a[i+1]-a[i]);
        array<int,2> res=[&]()->array<int,2>
        {
            if(s.size()<=1) return {0,0};
            int g=0;
            vector<int> v(s.begin(),s.end());
            for(int i=0;i<(int)v.size()-1;i++) g=gcd(g,v[i+1]-v[i]);
            if(g>mx) return {g,((v[0]%g)+g)%g};
            else return {-1,0};
        }();
        if(res[0]<=0) cout << res[0] << "\n";
        else cout << res[0] << " " << res[1] << "\n";
    }
    return 0;
}