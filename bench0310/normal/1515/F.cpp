#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x;
    cin >> n >> m >> x;
    vector<ll> sand(n+1,0);
    for(int i=1;i<=n;i++) cin >> sand[i];
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) p[i]=i;
    function<int(int)> find_set=[&](int a)->int
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    };
    vector<int> res;
    set<array<ll,2>> s;
    for(int i=1;i<=n;i++) s.insert({sand[i],i});
    auto merge_sets=[&](int a,int b,int e)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        if(v[a].size()<v[b].size()) swap(a,b);
        res.push_back(e);
        for(auto edge:v[b]) v[a].push_back(edge);
        p[b]=a;
        s.erase({sand[a],a});
        s.erase({sand[b],b});
        sand[a]+=(sand[b]-x);
        s.insert({sand[a],a});
        return 1;
    };
    while(s.size()>1)
    {
        int a=(*s.rbegin())[1];
        while(merge_sets(a,v[a].back()[0],v[a].back()[1])==0) v[a].pop_back();
    }
    if((*s.begin())[0]>=0)
    {
        cout << "YES\n";
        for(int e:res) cout << e << "\n";
    }
    else cout << "NO\n";
    return 0;
}