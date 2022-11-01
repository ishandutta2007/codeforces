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
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for(int &x:a) cin >> x;
        int k;
        cin >> k;
        vector<int> b(k);
        for(int &x:b) cin >> x;
        auto f=[&](int x)->array<ll,2>
        {
            ll c=1;
            while((x%m)==0)
            {
                c*=m;
                x/=m;
            }
            return {x,c};
        };
        auto split=[&](vector<int> v)->vector<array<ll,2>>
        {
            vector<array<ll,2>> r={{0,0}};
            for(int x:v)
            {
                auto [y,c]=f(x);
                if(r.back()[0]==y) r.back()[1]+=c;
                else r.push_back({y,c});
            }
            return r;
        };
        if(split(a)==split(b)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}