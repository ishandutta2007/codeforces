#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s;
    cin >> n >> m >> s;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        if(b!=s) v[a].push_back(b);
    }
    vector<int> c(n+1,0);
    vector<int> p(n+1,0);
    queue<int> q;
    auto add=[&](int a,int u)
    {
        if(c[a]==0)
        {
            c[a]=c[u];
            p[a]=u;
            q.push(a);
        }
        else if(c[a]!=c[u])
        {
            cout << "Possible\n";
            auto path=[&](int b)->vector<int>
            {
                vector<int> h={b};
                while(h.back()!=s) h.push_back(p[h.back()]);
                ranges::reverse(h);
                return h;
            };
            vector<int> one=path(a);
            vector<int> two=path(u);
            two.push_back(a);
            for(vector<int> t:{one,two})
            {
                cout << t.size() << "\n";
                for(int x:t) cout << x << " ";
                cout << "\n";
            }
            exit(0);
        }
    };
    for(int to:v[s])
    {
        c[s]=to;
        add(to,s);
    }
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a]) add(to,a);
    }
    cout << "Impossible\n";
    return 0;
}