#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=3005;
set<int> g[N];
int ecnt=0;
vector<int> euler;

void add(int a,int b)
{
    g[a].insert(b);
    g[b].insert(a);
    ecnt++;
}

void rm()
{
    for(int i=1;i<N;i++) g[i].clear();
    ecnt=0;
    euler.clear();
}

void ch(int a)
{
    int odd=0;
    for(int i=1;i<N;i++) odd+=(g[i].size()&1);
    if(!(odd==0||(odd==2&&(g[a].size()&1)))) ecnt=-1;
}

void go(int a)
{
    while(!g[a].empty())
    {
        int to=(*g[a].begin());
        g[a].erase(to);
        g[to].erase(a);
        ecnt--;
        go(to);
    }
    euler.push_back(a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    vector<array<int,2>> edges;
    vector<int> d(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges.push_back({a,b});
        d[a]^=1;
        d[b]^=1;
    }
    auto out=[](vector<int> res)
    {
        if(res.back()==-1) res.pop_back();
        cout << res.size() << "\n";
        for(int a:res) cout << a << " ";
        cout << "\n";
        exit(0);
    };
    for(int i=1;i<=n;i++)
    {
        //everything even || this and non-adjacent odd
        for(int to:v[i]) if(d[to]==0) add(i,to);
        for(auto [a,b]:edges) if(a!=i&&b!=i) add(a,b);
        ch(i);
        go(i);
        if(ecnt==0)
        {
            vector<int> res=euler;
            res.push_back(-1);
            for(int to:v[i])
            {
                if(d[to]==1)
                {
                    res.push_back(to);
                    res.push_back(i);
                }
            }
            out(res);
        }
        rm();
        //this and adjacent odd
        for(int odd:v[i])
        {
            if(d[odd]==1) add(odd,i);
            for(int to:v[i]) if(to!=odd&&d[to]==0) add(i,to);
            for(auto [a,b]:edges) if(a!=i&&b!=i) add(a,b);
            ch(i);
            go(i);
            if(ecnt==0)
            {
                vector<int> res=euler;
                res.push_back(-1);
                for(int to:v[i])
                {
                    if((to!=odd&&d[to]==1)||(to==odd&&d[to]==0))
                    {
                        res.push_back(to);
                        res.push_back(i);
                    }
                }
                out(res);
            }
            rm();
        }
    }
    cout << "0\n";
    return 0;
}