#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[2][n+1];
    const int sz=20;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[0][a].push_back(b);
        v[1][b].push_back(a);
    }
    const ll inf=(1ll<<60);
    vector<vector<ll>> d(n+1,vector<ll>(sz,inf));
    d[1][0]=0;
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q;
    q.push({0,1,0});
    vector<vector<array<ll,2>>> best(2,vector<array<ll,2>>(n+1,{inf,inf})); //lvl,mv
    auto mn=[](array<ll,2> &a,array<ll,2> b){a=min(a,b);};
    while(!q.empty())
    {
        auto [dx,a,lvl]=q.top();
        q.pop();
        if(d[a][lvl]<dx) continue;
        //cout << "[" << a << "," << lvl << "]=" << d[a][lvl] << endl;
        for(int to:v[lvl&1][a])
        {
            if(d[a][lvl]+1<d[to][lvl])
            {
                d[to][lvl]=d[a][lvl]+1;
                q.push({d[to][lvl],to,lvl});
            }
        }
        if(lvl+1<sz&&d[a][lvl]+(1ll<<lvl)<d[a][lvl+1])
        {
            d[a][lvl+1]=d[a][lvl]+(1ll<<lvl);
            q.push({d[a][lvl+1],a,lvl+1});
        }
        if(lvl+1==sz) mn(best[(lvl+1)&1][a],{lvl+1,d[a][lvl]+(1ll<<lvl)-((1ll<<(lvl+1))-1)});
    }
    ll res=inf;
    for(int i=0;i<sz;i++) res=min(res,d[n][i]);
    if(res<inf)
    {
        cout << (res%mod) << "\n";
        return 0;
    }
    //q: lvl,mv,a
    for(int i=1;i<=n;i++) if(best[sz&1][i][0]!=inf) q.push({best[sz&1][i][0],best[sz&1][i][1],i});
    while(!q.empty())
    {
        auto [lvl,mv,a]=q.top();
        q.pop();
        if(best[lvl&1][a]<array<ll,2>{lvl,mv}) continue;
        //cout << "[" << a << "," << lvl << "]={" << lvl << "," << mv << "}" << endl;
        for(int to:v[lvl&1][a])
        {
            if(array<ll,2>{lvl,mv+1}<best[lvl&1][to])
            {
                best[lvl&1][to]={lvl,mv+1};
                q.push({lvl,mv+1,to});
            }
        }
        if(array<ll,2>{lvl+1,mv}<best[(lvl+1)&1][a])
        {
            best[(lvl+1)&1][a]={lvl+1,mv};
            q.push({lvl+1,mv,a});
        }
    }
    if(best[0][n]>best[1][n]) cout << (fpow(2,best[1][n][0])+best[1][n][1]-1+mod)%mod << "\n";
    else cout << (fpow(2,best[0][n][0])+best[0][n][1]-1+mod)%mod << "\n";
    return 0;
}