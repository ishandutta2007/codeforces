#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
vector<array<int,2>> p(N,{0,0});
vector<int> sz(N,1);
vector<array<int,3>> rp;
vector<array<int,2>> rsz;

array<int,2> find_set(int a)
{
    //cout << "find parent of " << a;
    int x=0;
    while(a!=p[a][0])
    {
        x^=p[a][1];
        a=p[a][0];
        //cout << "->" << a;
    }
    //cout << endl;
    return {a,x};
}

bool union_sets(int a,int b,bool r=0)
{
    //cout << "union " << a << " " << b << endl;
    auto [ta,x]=find_set(a);
    auto [tb,y]=find_set(b);
    tie(a,b)={ta,tb};
    //cout << "parent " << a << " " << b << endl;
    //cout << (x^y^1) << endl;
    if(a==b) return ((x^y^1)==1);
    else
    {
        if(sz[a]<sz[b]) swap(a,b);
        if(r)
        {
            rp.push_back({b,p[b][0],p[b][1]});
            rsz.push_back({a,sz[a]});
        }
        //cout << "connect " << b << " to " << a << endl;
        p[b]={a,x^y^1};
        sz[a]+=sz[b];
        return 0;
    }
}

void rollback()
{
    reverse(rp.begin(),rp.end());
    reverse(rsz.begin(),rsz.end());
    for(auto [a,v1,v2]:rp) p[a]={v1,v2};
    for(auto [a,val]:rsz) sz[a]=val;
    rp.clear();
    rsz.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) p[i]={i,0};
    vector<int> g(n+1,0);
    for(int i=1;i<=n;i++) cin >> g[i];
    vector<array<int,2>> edges(m);
    vector<bool> bad(k+1,0);
    for(auto &[a,b]:edges)
    {
        cin >> a >> b;
        if(g[a]==g[b]) if(union_sets(a,b)==1) bad[g[a]]=1;
    }
    ll good=0;
    for(int i=1;i<=k;i++) good+=(bad[i]==0);
    ll res=(good*(good-1)/2);
    vector<array<int,4>> ext;
    for(auto [a,b]:edges)
    {
        if(g[a]!=g[b]&&bad[g[a]]==0&&bad[g[b]]==0)
        {
            if(g[a]>g[b]) swap(a,b);
            ext.push_back({g[a],g[b],a,b});
        }
    }
    sort(ext.begin(),ext.end());
    int l=0;
    while(l<(int)ext.size())
    {
        int r=l;
        vector<array<int,2>> now;
        while(r<(int)ext.size()&&ext[r][0]==ext[l][0]&&ext[r][1]==ext[l][1])
        {
            now.push_back({ext[r][2],ext[r][3]});
            r++;
        }
        bool ok=1;
        for(auto [a,b]:now) ok&=(union_sets(a,b,1)==0);
        if(ok==0) res--;
        rollback();
        l=r;
    }
    cout << res << "\n";
    return 0;
}