#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 500005

vector<int> g[MAXN];
int res[MAXN],a[MAXN],mk[MAXN],p;

void dfs(int u)
{
    mk[u]=1;
    if(!res[u])
    {
        res[u]=p;
        p--;
    }

    for(auto y : g[u])
        if(!mk[y])
            dfs(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        p=n;
        res[n+1]=n+1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i]!=-1)
                g[a[i]].push_back(i);
        }

        for(int i=n+1;i;i--)
            if(g[i].size() && !mk[i])
                dfs(i);
        for(int i=1;i<=n;i++)
            if(!res[i])
            {
                res[i]=p;
                p--;
            }

        bool ok=1;
        stack<pii> s;
        s.push(pii(n+1,n+1));
        for(int i=n;i;i--)
        {
            while(s.top().first<res[i])
                s.pop();
            if(a[i]!=-1 && s.top().second!=a[i])
                ok=0;
            s.push(pii(res[i],i));
        }
        if(!ok)
            db(-1)
        else
        {
            for(int i=1;i<=n;i++)
                cout << res[i] << ' ';
            cout << '\n';
        }

        for(int i=0;i<=n+1;i++)
        {
            g[i].clear();
            res[i]=0;
            a[i]=0;
            mk[i]=0;
        }
    }

    return 0;
}