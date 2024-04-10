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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<int> c(m+1,0);
        for(int i=1;i<=m;i++) cin >> c[i];
        multiset<int> col;
        vector<bool> req(n+1,0);
        for(int i=1;i<=n;i++) req[b[i]]=1;
        for(int i=1;i<=m;i++) if(req[c[i]]) col.insert(c[i]);
        vector<int> id[n+1];
        for(int i=1;i<=n;i++) id[b[i]].push_back(i);
        vector<int> paint[n+1];
        for(int i=1;i<=n;i++) if(a[i]!=b[i]) paint[b[i]].push_back(i);
        vector<int> res(m+1,0);
        bool ok=1;
        for(int i=1;i<=m;i++)
        {
            if(!id[c[i]].empty())
            {
                if(!paint[c[i]].empty())
                {
                    res[i]=paint[c[i]].back();
                    paint[c[i]].pop_back();
                }
                else res[i]=id[c[i]][0];
            }
            else
            {
                if(col.empty()) ok=0;
                else
                {
                    int x=(*col.begin());
                    if(!paint[x].empty()) res[i]=paint[x].back();
                    else
                    {
                        res[i]=id[x][0];
                        if(a[id[x][0]]==x) paint[x].push_back(id[x][0]);
                    }
                }
            }
            if(req[c[i]]) col.erase(col.find(c[i]));
            a[res[i]]=c[i];
        }
        for(int i=1;i<=n;i++) ok&=(a[i]==b[i]);
        if(ok)
        {
            cout << "YES\n";
            for(int i=1;i<=m;i++) cout << res[i] << " \n"[i==m];
        }
        else cout << "NO\n";
    }
    return 0;
}