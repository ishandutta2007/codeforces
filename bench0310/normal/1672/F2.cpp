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
        vector<int> a(n,0);
        vector<int> c(n+1,0);
        int m=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            m=max(m,(++c[a[i]]));
        }
        int x=0;
        for(int i=1;i<=n;i++) if(c[i]==m) x=i;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        vector<int> v[n+1];
        for(int i=0;i<n;i++) v[b[i]].push_back(a[i]);
        bool cycle=0;
        vector<int> st(n+1,0);
        st[x]=2;
        function<void(int)> dfs=[&](int e)
        {
            st[e]=1;
            for(int to:v[e])
            {
                if(st[to]==0) dfs(to);
                else cycle|=(st[to]==1);
            }
            st[e]=2;
        };
        for(int i=1;i<=n;i++) if(st[i]==0) dfs(i);
        if(!cycle) cout << "AC\n";
        else cout << "WA\n";
    }
    return 0;
}