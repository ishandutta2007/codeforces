#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    auto solve=[&](int r)->ll
    {
        if(r==0) return 1;
        vector uncovered(n+1,vector(r+1,ll(0)));
        vector black(n+1,vector(r+1,ll(0)));
        vector uncovered_pre(n+1,vector(r+1,ll(0)));
        vector black_suf(n+1,vector(r+1,ll(0)));
        function<void(int,int)> dfs=[&](int a,int p)
        {
            for(int to:v[a]) if(to!=p) dfs(to,a);
            uncovered[a][0]=black[a][0]=1;
            for(int to:v[a])
            {
                if(to==p) continue;
                uncovered[a][0]=mul(uncovered[a][0],black[to][r]);
                black[a][0]=mul(black[a][0],add(black_suf[to][0],uncovered_pre[to][r-1]));
            }
            for(int d=1;d<=r;d++)
            {
                ll xa=1;
                ll xb=1;
                ll ya=1;
                ll yb=1;
                for(int to:v[a])
                {
                    if(to==p) continue;
                    xa=mul(xa,add(uncovered_pre[to][d-1],black_suf[to][r-d]));
                    xb=mul(xb,add((d>=2?uncovered_pre[to][d-2]:0),black_suf[to][r-d]));
                    ya=mul(ya,add(black_suf[to][d-1],(d<r?uncovered_pre[to][r-d-1]:0)));
                    yb=mul(yb,add(black_suf[to][d],(d<r?uncovered_pre[to][r-d-1]:0)));
                }
                uncovered[a][d]=sub(xa,xb);
                black[a][d]=sub(ya,yb);
            }
            uncovered_pre[a][0]=uncovered[a][0];
            for(int i=1;i<=r;i++) uncovered_pre[a][i]=uncovered_pre[a][i-1]+uncovered[a][i];
            black_suf[a][r]=black[a][r];
            for(int i=r-1;i>=0;i--) black_suf[a][i]=black_suf[a][i+1]+black[a][i];
        };
        dfs(1,0);
        return black_suf[1][0];
    };
    ll sum=0;
    ll res=n;
    for(int r=0;r<=n;r++)
    {
        ll t=solve(r);
        t=sub(t,sum);
        res=add(res,mul(sub(r,1),t));
        sum=add(sum,t);
    }
    for(int i=1;i<=n;i++) res=mul(res,(mod+1)/2);
    cout << res << "\n";
    return 0;
}