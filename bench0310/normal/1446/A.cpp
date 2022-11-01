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
        ll w;
        cin >> n >> w;
        vector<array<ll,2>> v;
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            if(a>w) continue;
            if(a>=(w+1)/2) res={i};
            else v.push_back({a,i});
        }
        if(res.empty())
        {
            ll sum=0;
            for(auto [a,id]:v)
            {
                if(sum+a<=w)
                {
                    sum+=a;
                    res.push_back(id);
                }
            }
            if(sum<(w+1)/2) res.clear();
        }
        if(!res.empty())
        {
            cout << res.size() << "\n";
            for(int a:res) cout << a << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    
    return 0;
}