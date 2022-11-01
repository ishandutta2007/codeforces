#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<array<ll,2>,int> g;
vector<bool> vis(61,0);

int grundy(int a,ll m)
{
    if(g.find({a,m})!=g.end()) return g[{a,m}];
    vector<int> v;
    for(int i=1;i<=a;i++) if((m&(1ll<<i))==0) v.push_back(grundy(a-i,m|(1ll<<i)));
    for(int x:v) vis[x]=1;
    for(int j=0;j<=60;j++)
    {
        if(vis[j]==0)
        {
            g[{a,m}]=j;
            break;
        }
    }
    for(int x:v) vis[x]=0;
    return g[{a,m}];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        x^=grundy(a,0);
    }
    if(x==0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}