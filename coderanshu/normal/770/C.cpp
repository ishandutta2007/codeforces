#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) int x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
vector<vector<int>> v;
vector<bool> check;
vector<int> s,ans;
vector<vector<int>> vv;
set<int> t;
void dfs(int x)
{
    check[x]=true;
    t.insert(x);
    for(auto i:v[x])
    {
        if(!check[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    fast
    fast
    int n,k,a,b;
    cin>>n>>k;
    vv.resize(n+1);
    v.resize(n+1);
    check.resize(n+1);
    int cnt[n+1]={};
    for(int i=0;i<k;i++)
    {
        cin>>a;
        s.pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>a;
            v[i].pb(a);
            vv[a].pb(i);
            ++cnt[i];
        }
    }
    set<pair<int,int>> se;
    for(auto i:s)
    {
        dfs(i);
    }
    for(auto j:t)
    {
        se.insert({cnt[j],j});
    }
    while(!se.empty())
    {
        if((*se.begin()).F!=0)
        {
            cout<<-1;
            return 0;
        }
        ans.pb((*se.begin()).S);
        int xx=se.begin()->S;
        se.erase(se.begin());
        for(auto k:vv[xx])
        {
            if(se.count({cnt[k],k}))
                {se.erase({cnt[k],k});
                cnt[k]--;
                se.insert({cnt[k],k});}
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}