    #include <bits/stdc++.h>
    #define db(x) cout << (x) << '\n';
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll,ll> pii;
    typedef pair<ll,pii> pip;
    typedef pair<pii,ll> ppi;
    typedef pair<pii,pii> ppp;
    typedef pair<ld,ll> pli;
    typedef pair<pii,string> pps;
    typedef pair<char,ll> pci;
    typedef complex<double> point;
    typedef vector<point> polygon;
    #define pi (acos(-1))
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    #define MAXN 100005
     
    int d[MAXN],cant[MAXN],cont;
    vector<int> g[MAXN];
    bool mk[MAXN];
     
    int find(int u)
    {
        if(d[u]<0)
            return u;
        d[u]=find(d[u]);
        return d[u];
    }
     
    void join(int u,int v)
    {
        if(u==v)
            return ;
        u=find(u);
        v=find(v);
        if(d[u]>d[v])
            swap(u,v);
        d[u]+=d[v];
        d[v]=u;
        cont++;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
     
        int n,m,u,v;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            d[i]=-1;
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
            cant[u]++;
            cant[v]++;
        }
     
        vector<pii> x;
        for(int i=0;i<n;i++)
            x.push_back(pii(cant[i],i));
     
        sort(x.begin(),x.end());
     
        for(int i=0;i<n;i++)
        {
            if(!i || find(x[i].second)!=find(x[0].second))
            {
                u=x[i].second;
                for(auto v : g[u])
                    mk[v]=1;
                for(int i=0;i<n;i++)
                {
                    if(!mk[i] && find(i)!=find(u))
                        join(u,i);
                    mk[i]=0;
                }
            }
        }
        db(n-cont-1)
     
        return 0;
    }