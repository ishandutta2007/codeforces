#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 i128;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        v[a].push_back({b,d});
        v[b].push_back({a,d});
    }
    int k;
    cin >> k;
    string z;
    cin >> z;
    z="$"+z;
    vector<vector<array<int,2>>> passes(k),fines(k);
    for(int i=0;i<k;i++)
    {
        int p;
        cin >> p;
        passes[i].push_back({0,p});
    }
    for(int i=0;i<k;i++)
    {
        int f;
        cin >> f;
        fines[i].push_back({0,f});
    }
    int T;
    cin >> T;
    int q;
    cin >> q;
    vector<int> queries[n+1];
    const ll inf=(1ll<<60);
    vector<ll> res(q+1,inf);
    for(int i=1;i<=q;i++)
    {
        int t;
        cin >> t;
        if(t<=2)
        {
            char a;
            int c;
            cin >> a >> c;
            if(t==1) passes[a-'A'].push_back({i,c});
            else fines[a-'A'].push_back({i,c});
        }
        else
        {
            int a;
            cin >> a;
            queries[a].push_back(i);
        }
    }
    vector<ll> depth(n+1,0);
    vector<int> u(n+1,0);
    vector<ll> du(n+1,0);
    vector<int> sz(n+1,0);
    vector<int> big_ch(n+1,0);
    function<void(int,int,int)> dfs=[&](int a,int p,int up)
    {
        u[a]=up;
        du[a]=depth[a]-depth[up];
        sz[a]=1;
        for(auto [to,d]:v[a])
        {
            if(to==p) continue;
            depth[to]=depth[a]+d;
            dfs(to,a,(z[a]==z[to]?up:a));
            sz[a]+=sz[to];
            if(sz[to]>sz[big_ch[a]]) big_ch[a]=to;
        }
    };
    dfs(1,0,1);
    auto get_cost=[&](vector<array<int,2>> &e,int id)->int
    {
        auto it=ranges::lower_bound(e,array<int,2>{id+1,0});
        it--;
        return (*it)[1];
    };
    auto get_costs=[&](vector<vector<array<int,2>>> &e,int id)->vector<int>
    {
        vector<int> cost(k);
        for(int i=0;i<k;i++) cost[i]=get_cost(e[i],id);
        return cost;
    };
    function<set<int>(int,int)> go=[&](int a,int par)->set<int>
    {
        set<int> opt;
        if(big_ch[a]!=0) opt=go(big_ch[a],a);
        if(big_ch[a]!=0&&z[big_ch[a]]!=z[a]) opt.clear();
        opt.insert(du[a]%T);
        for(auto [to,c]:v[a])
        {
            if(to==par||to==big_ch[a]) continue;
            set<int> t=go(to,a);
            if(z[a]==z[to]) for(int x:t) opt.insert(x);
        }
        auto get_range=[&](int l,int r)->bool
        {
            auto it=opt.lower_bound(l);
            return (it!=opt.end()&&(*it)<=r);
        };
        for(int id:queries[a])
        {
            if(z[a]=='A')
            {
                res[id]=0;
                continue;
            }
            vector<int> path={u[a]};
            while(u[path.back()]!=1) path.push_back(u[path.back()]);
            vector<int> pass=get_costs(passes,id);
            vector<int> fine=get_costs(fines,id);
            vector<array<ll,2>> e;
            auto add=[&](int l,int r,ll x){e.push_back({l,x}); e.push_back({r+1,-x});};
            ranges::reverse(path);
            for(int b:path)
            {
                ll p=pass[z[b]-'A'];
                ll f=fine[z[b]-'A'];
                int s=(depth[b]%T);
                ll big_cnt=(du[b]+T-1)/T;
                ll small_cnt=big_cnt-1;
                ll big=min(i128(p),i128(big_cnt)*f);
                ll small=min(i128(p),i128(small_cnt)*f);
                int l=(du[b]+T-1)%T;
                //[T-l..T]+s -> big
                //[1..T-l-1]+s -> small
                add(0,T-1,small);
                int x=(T-l+s)%T;
                int y=(T+s)%T;
                if(x<=y) add(x,y,big-small);
                else
                {
                    add(0,y,big-small);
                    add(x,T-1,big-small);
                }
            }
            int s=(depth[u[a]]%T);
            ranges::sort(e);
            int events=e.size();
            ll now=0;
            for(int i=0;i+1<events;i++)
            {
                now+=e[i][1];
                if(e[i][0]!=e[i+1][0])
                {
                    int l=(e[i][0]-s+T)%T;
                    int r=(e[i+1][0]-1-s+T)%T;
                    if((l<=r&&get_range(l,r))||(l>r&&(get_range(0,r)||get_range(l,T-1)))) res[id]=min(res[id],now);
                }
            }
        }
        return opt;
    };
    go(1,0);
    for(int i=1;i<=q;i++) if(res[i]!=inf) cout << res[i] << "\n";
    return 0;
}