#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=30000+5;

int n,m;
vector<int>g[N];
bool seen[N];

vector<int>kek;
set<int>no[N];

inline void dfs(int nod)
{
    seen[nod]=1;
    for(auto &nou:g[nod])
    {
        if(seen[nou]==0)
        {
            dfs(nou);
        }
    }
    kek.push_back(nod);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        no[x].insert(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(seen[i]==0)
        {
            dfs(i);
        }
    }
    int last=-1;
    for(auto &x:kek)
    {
        if(last!=-1 && no[last].find(x)!=no[last].end())
        {
            cout<<"-1\n";
            return 0;
        }
        last=x;
    }
    for(auto &x:kek)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}