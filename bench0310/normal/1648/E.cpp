#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,3>> ini_edges(m);
        vector<array<int,2>> qry_edges(m);
        set<array<int,2>> bad;
        for(int i=0;i<m;i++)
        {
            auto &[c,a,b]=ini_edges[i];
            cin >> a >> b >> c;
            qry_edges[i]={a,b};
            bad.insert({min(a,b),max(a,b)});
        }
        ranges::sort(ini_edges);
        vector<int> p_one(n+1,0);
        vector<int> p_two(n+1,0);
        vector<vector<int>> groups(n+1);
        vector<vector<int>> cc(n+1);
        vector<array<int,3>> opt_edges;
        for(int i=1;i<=n;i++)
        {
            p_one[i]=p_two[i]=i;
            groups[i]=cc[i]={i};
        }
        function<int(int,int)> find_set=[&](int a,int id)->int
        {
            vector<int> &p=(id==1?p_one:p_two);
            if(p[a]==a) return a;
            else return p[a]=find_set(p[a],id);
        };
        auto merge_sets_two=[&](int a,int b)
        {
            a=find_set(a,2);
            b=find_set(b,2);
            if(cc[a].size()<cc[b].size()) swap(a,b);
            for(int x:cc[b]) cc[a].push_back(x);
            cc[b].clear();
            p_two[b]=a;
        };
        auto connect=[&](int a,int b)->array<int,2>
        {
            for(int x:cc[a]) for(int y:cc[b]) if(!bad.contains({min(x,y),max(x,y)})) return {x,y};
            return {-1,-1};
        };
        auto merge_sets_one=[&](int a,int b,int c)
        {
            a=find_set(a,1);
            b=find_set(b,1);
            if(a==b) return;
            vector<int> now=groups[a];
            vector<array<int,2>> delay;
            for(int x:groups[b])
            {
                int p=0;
                for(int y:now)
                {
                    auto [tx,ty]=connect(x,y);
                    if(tx!=-1)
                    {
                        if(p==0)
                        {
                            p=ty;
                            delay.push_back({tx,ty});
                        }
                        else merge_sets_two(p,ty);
                        opt_edges.push_back({tx,ty,c});
                    }
                }
                vector<int> nxt;
                for(int y:now) if(!cc[y].empty()) nxt.push_back(y);
                now=nxt;
            }
            for(auto [x,y]:delay) merge_sets_two(x,y);
            vector<int> tmp;
            for(int x:groups[a]) if(!cc[x].empty()) tmp.push_back(x);
            for(int x:groups[b]) if(!cc[x].empty()) tmp.push_back(x);
            groups[a]=tmp;
            groups[b].clear();
            p_one[b]=a;
        };
        for(auto [c,a,b]:ini_edges) merge_sets_one(a,b,c);
        vector<vector<array<int,2>>> v(n+1);
        for(auto [a,b,c]:opt_edges)
        {
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        vector<array<int,18>> up(n+1);
        vector<array<int,28>> mx(n+1);
        for(int i=1;i<=n;i++)
        {
            up[i].fill(0);
            mx[i].fill(0);
        }
        vector<int> depth(n+1,0);
        function<void(int)> dfs=[&](int a)
        {
            depth[a]=depth[up[a][0]]+1;
            for(int i=1;i<18;i++)
            {
                up[a][i]=up[up[a][i-1]][i-1];
                mx[a][i]=max(mx[a][i-1],mx[up[a][i-1]][i-1]);
            }
            for(auto [to,c]:v[a])
            {
                if(to==up[a][0]) continue;
                up[to][0]=a;
                mx[to][0]=c;
                dfs(to);
            }
        };
        dfs(1);
        auto cost=[&](int a,int b)->int
        {
            int res=0;
            if(depth[a]>depth[b]) swap(a,b);
            for(int i=17;i>=0;i--)
            {
                if(depth[up[b][i]]>=depth[a])
                {
                    res=max(res,mx[b][i]);
                    b=up[b][i];
                }
            }
            if(a==b) return res;
            for(int i=17;i>=0;i--)
            {
                if(up[a][i]!=up[b][i])
                {
                    res=max({res,mx[a][i],mx[b][i]});
                    tie(a,b)={up[a][i],up[b][i]};
                }
            }
            return max({res,mx[a][0],mx[b][0]});
        };
        for(auto [a,b]:qry_edges) cout << cost(a,b) << " ";
        cout << "\n";
    }
    return 0;
}