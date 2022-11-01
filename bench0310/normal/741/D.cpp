#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int N=500005;
vector<int> v[N];
vector<int> val(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<int> x(N,0);
vector<int> d(N,0);
vector<int> res(N,0);

void dfs(int a)
{
    sz[a]=1;
    for(int to:v[a])
    {
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

unordered_map<int,int> solve(int a)
{
    if(big[a]==0) return {{0,0}};
    unordered_map<int,int> c=solve(big[a]);
    res[a]=max(res[a],res[big[a]]);
    x[a]=x[big[a]]^(1<<val[big[a]]);
    d[a]=d[big[a]]+1;
    if(c.find(x[a])!=c.end()) res[a]=max(res[a],c[x[a]]+d[a]);
    for(int i=0;i<22;i++) if(c.find(x[a]^(1<<i))!=c.end()) res[a]=max(res[a],c[x[a]^(1<<i)]+d[a]);
    auto add=[&](int one,int two)
    {
        if(c.find(one)==c.end()) c[one]=two;
        else c[one]=max(c[one],two);
    };
    for(int to:v[a])
    {
        if(to==big[a]) continue;
        unordered_map<int,int> tmp=solve(to);
        res[a]=max(res[a],res[to]);
        unordered_map<int,int> now;
        now.reserve(tmp.size());
        now.max_load_factor(0.25);
        for(auto [one,two]:tmp) now[one^x[to]^(1<<val[to])]=two+d[to]+1;
        for(auto [one,two]:now)
        {
            if(c.find(one^x[a])!=c.end()) res[a]=max(res[a],two+c[one^x[a]]+d[a]);
            for(int i=0;i<22;i++) if(c.find(one^x[a]^(1<<i))!=c.end()) res[a]=max(res[a],two+c[one^x[a]^(1<<i)]+d[a]);
        }
        if(now.find(0)!=now.end()) res[a]=max(res[a],now[0]);
        for(int i=0;i<22;i++) if(now.find((1<<i))!=now.end()) res[a]=max(res[a],now[(1<<i)]);
        for(auto [one,two]:now) add(one^x[a],two-d[a]);
    }
    add(x[a],-d[a]);
    //cout << "actual c[" << a << "]" << endl;
    //for(auto [one,two]:c) cout << "[" << bitset<22>(one^x[a]).to_string() << "," << two+d[a] << "]" << endl;
    //cout << endl;
    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        int p;
        char c;
        cin >> p >> c;
        v[p].push_back(i);
        val[i]=(c-'a');
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}