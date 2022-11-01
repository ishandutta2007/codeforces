#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,s,d;
    cin >> n >> q >> s >> d;
    vector<int> a(n+1,0);
    vector<int> h(1000001,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        h[a[i]]=i;
    }
    set<int> unreachable;
    for(int i=1;i<=n;i++) if(i!=s) unreachable.insert(a[i]);
    set<int> opt;
    set<array<int,2>> nxt;
    auto add_opt=[&](int p)
    {
        opt.insert(p);
        auto it=unreachable.lower_bound(p);
        if(it!=unreachable.end()) nxt.insert({(*it)-p,(*it)});
        if(it!=unreachable.begin())
        {
            it--;
            nxt.insert({p-(*it),(*it)});
        }
    };
    add_opt(a[s]-d);
    add_opt(a[s]+d);
    auto rm_unreachable=[&](int p)
    {
        unreachable.erase(p);
        auto it=opt.lower_bound(p);
        if(it!=opt.end()) add_opt(*it);
        if(it!=opt.begin())
        {
            it--;
            add_opt(*it);
        }
    };
    vector<array<int,3>> queries(q); //k,e,id
    for(int i=0;i<q;i++)
    {
        int e,k;
        cin >> e >> k;
        queries[i]={k,e,i};
    }
    sort(queries.begin(),queries.end());
    vector<bool> res(q,0);
    vector<bool> reachable(n+1,0);
    reachable[s]=1;
    for(auto [k,e,id]:queries)
    {
        while(!nxt.empty()&&(*nxt.begin())[0]<=k)
        {
            int p=(*nxt.begin())[1];
            nxt.erase(nxt.begin());
            if(reachable[h[p]]==0)
            {
                rm_unreachable(p);
                reachable[h[p]]=1;
                add_opt(p-d);
                add_opt(p+d);
            }
        }
        res[id]=reachable[e];
    }
    for(int i=0;i<q;i++)
    {
        if(res[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}