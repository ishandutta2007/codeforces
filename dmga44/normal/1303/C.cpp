#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

bool mk[26];
vector<int> res,g[26];

void dfs(int u)
{
    mk[u]=1;
    res.push_back(u);
    for(auto v : g[u])
        if(!mk[v])
            dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        res.clear();
        for(int i=0;i<26;i++)
        {
            mk[i]=0;
            g[i].clear();
        }

        string s;
        cin >> s;
        if(s.size()==1)
        {
            db("YES")
            for(int i=0;i<26;i++)
                if(!mk[i])
                    cout << (char)(i+'a');
            cout << '\n';
            continue;
        }

        int n=s.size();
        vector<int> f(26);
        bool ok=1;
        for(int i=0;i<n-1;i++)
        {
            int u=s[i]-'a';
            int v=s[i+1]-'a';
            bool okk=1;
            for(auto y : g[u])
                if(y==v)
                    okk=0;

            if(!okk)
                continue;
            g[u].push_back(v);
            g[v].push_back(u);
            f[u]++;
            f[v]++;
            if(f[u]>2)
                ok=0;
            if(f[v]>2)
                ok=0;
        }
        if(!ok)
        {
            db("NO")
            continue;
        }

        int ini=-1;
        for(int i=0;i<26;i++)
            if(g[i].size()==1)
                ini=i;
        if(ini==-1)
        {
            db("NO")
            continue;
        }
        dfs(ini);

        db("YES")
        for(auto y : res)
            cout << (char)(y+'a');
        for(int i=0;i<26;i++)
            if(!mk[i])
                cout << (char)(i+'a');
        cout << '\n';
    }

    return 0;
}