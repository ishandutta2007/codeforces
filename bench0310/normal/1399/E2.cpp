#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> v[N];
vector<ll> w(N,0);
vector<int> c(N,0);
vector<int> up(N,0);
vector<int> leaves(N,0);
vector<ll> dist(N,0);

void dfs(int a,int p=0)
{
    for(auto [to,id]:v[a])
    {
        if(to==p) continue;
        up[to]=id;
        dist[to]=dist[a]+w[id];
        dfs(to,a);
        leaves[a]+=leaves[to];
    }
    if(leaves[a]==0) leaves[a]=1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll inf=(1ll<<60);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll s;
        cin >> n >> s;
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b >> w[i] >> c[i];
            v[a].push_back({b,i});
            v[b].push_back({a,i});
        }
        dfs(1);
        ll sum=0;
        vector<ll> one,two;
        for(int i=2;i<=n;i++)
        {
            if(v[i].size()==1) sum+=dist[i];
            ll x=w[up[i]];
            while(x)
            {
                if(c[up[i]]==1) one.push_back((x-(x/2))*leaves[i]);
                else two.push_back((x-(x/2))*leaves[i]);
                x/=2;
            }
        }
        sort(one.begin(),one.end(),greater<ll>());
        sort(two.begin(),two.end(),greater<ll>());
        vector<ll> twosum(two.size(),0);
        if(!two.empty()) twosum[0]=two[0];
        for(int i=1;i<(int)two.size();i++) twosum[i]=twosum[i-1]+two[i];
        ll res=inf;
        ll onesum=0;
        auto solve=[&](ll x)->ll
        {
            if(x<=0) return 0;
            int l=-1,r=twosum.size();
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(twosum[m]>=x) r=m;
                else l=m;
            }
            if(r==(int)twosum.size()) return inf;
            else return (2*(r+1));
        };
        res=min(res,solve(sum-s));
        for(int i=0;i<(int)one.size();i++)
        {
            onesum+=one[i];
            res=min(res,i+1+solve(sum-s-onesum));
        }
        cout << res << "\n";
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            w[i]=c[i]=up[i]=leaves[i]=dist[i]=0;
        }
    }
    return 0;
}