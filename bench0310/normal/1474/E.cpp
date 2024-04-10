#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto sq=[](ll a)->ll{return (a*a);};
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll res=sq(n-1);
        vector<int> v;
        v.push_back(1);
        vector<array<int,2>> ops;
        for(int i=n/2+1;i<=n-1;i++)
        {
            v.push_back(i);
            ops.push_back({i,1});
            res+=sq(i-1);
        }
        v.push_back(n);
        for(int i=2;i<=(n/2);i++)
        {
            v.push_back(i);
            ops.push_back({i,n});
            res+=sq(n-i);
        }
        ops.push_back({1,n});
        vector<int> p(n+1,0);
        for(int i=0;i<n;i++) p[v[i]]=v[(i+1)%n];
        cout << res << "\n";
        for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
        cout << ops.size() << "\n";
        for(auto [a,b]:ops) cout << a << " " << b << "\n";        
    }
    return 0;
}