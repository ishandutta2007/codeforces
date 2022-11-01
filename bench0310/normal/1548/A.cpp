#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    int res=0;
    auto good=[&](int a)->int
    {
        return (v[a].empty()||(*v[a].rbegin())<a);
    };
    for(int i=1;i<=n;i++) res+=good(i);
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t<=2)
        {
            int a,b;
            cin >> a >> b;
            res-=(good(a)+good(b));
            if(t==1)
            {
                v[a].insert(b);
                v[b].insert(a);
            }
            else
            {
                v[a].erase(b);
                v[b].erase(a);
            }
            res+=(good(a)+good(b));
        }
        else cout << res << "\n";
    }
    return 0;
}