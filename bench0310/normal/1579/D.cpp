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
        priority_queue<array<int,2>> q;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a>0) q.push({a,i});
        }
        vector<array<int,2>> res;
        while(q.size()>=2)
        {
            auto [c,a]=q.top();
            q.pop();
            auto [d,b]=q.top();
            q.pop();
            res.push_back({a,b});
            if(c-1>0) q.push({c-1,a});
            if(d-1>0) q.push({d-1,b});
        }
        cout << res.size() << "\n";
        for(auto [a,b]:res) cout << a << " " << b << "\n";
    }
    return 0;
}