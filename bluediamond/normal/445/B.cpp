#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=50+5;

int n,m;
vector<int>g[N];
bool viz[N];
int cnt=0;

void dfs(int nod)
{
    cnt++;
    viz[nod]=1;
    for(auto &nou:g[nod])
    {
        if(viz[nou]) continue;
        dfs(nou);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll res=1LL;
    for(int i=1;i<=n;i++)
    {
        if(viz[i]==0)
        {
            cnt=0;
            dfs(i);
            cnt--;
            res*=(1LL<<cnt);
        }
    }
    cout<<res<<"\n";
    return 0;
}