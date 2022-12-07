#include <bits/stdc++.h>
#define int long long
using namespace std;

struct CHT_line
{
    int k, b, r;
    operator < (const CHT_line &x) const
    {
        return r>x.r;
    }
};

class CHT
{
public:

    CHT(string k, string f)
    {
        if(f=="min")
        {
            dy=1;
            if(k=="inc") dx=1;
            else dx=-1;
        }
        else
        {
            dy=-1;
            if(k=="inc") dx=-1;
            else dx=1;
        }
    }

    void insert(int k, int b)
    {
        k*=(dx*dy), b*=dy;
        while(hull.size())
        {
            int k2=hull.back().k, b2=hull.back().b, r2=hull.back().r, r;
            if(k==k2)
            {
                if(b>b2) break;
                else hull.pop_back();
            }
            else
            {
                if(b<=b2) r=(b2-b)/(k-k2);
                else r=-((b-b2)/(k-k2)+1);

                if(r>=r2) hull.pop_back();
                else
                {
                    hull.push_back({k, b, r});
                    break;
                }
            }
        }
        if(hull.size()==0) hull.push_back({k, b, inf});
    }

    int query(int x)
    {
        x*=dx;
        CHT_line cu={0, 0, x};
        int p=upper_bound(hull.begin(), hull.end(), cu)-hull.begin()-1;
        return hull[p].k*x+hull[p].b;
    }

private:

    int dx, dy;
    vector <CHT_line> hull;
    static const int inf=1e18;
};

const int sz=5e5+10, inf=1e18;
vector <int> sv[sz];
int n, si[sz], dp[sz], be=inf;
void dfs(int v, int pr)
{
    si[v]=1, dp[v]=inf;
    vector <pair <int, int> > sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v), si[v]+=si[ne], sp.push_back({si[ne], ne});
    }
    sort(sp.begin(), sp.end());
    CHT hull("inc", "min");
    for(int a=0; a<sp.size(); a++)
    {
        int ne=sp[a].second, q=si[v]-si[ne];
        dp[v]=min(dp[v], dp[ne]+q*(q-1)/2);

        q+=(n-si[v]);
        if(a) be=min(be, hull.query(-q)+dp[ne]+(q*q-q)/2);
        hull.insert(si[ne], dp[ne]+(si[ne]*si[ne]+si[ne])/2);
    }
    if(dp[v]==inf) dp[v]=0;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    be=min(be, dp[0]);
    cout<<n*(n-1)-be;
}