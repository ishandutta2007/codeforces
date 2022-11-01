#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n,0);
    int N=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        N=max(N,2*a[i]);
    }
    const ll mod=1000000007;
    auto add=[&](ll x,ll y)->ll{return (x+y)%mod;};
    auto sub=[&](ll x,ll y)->ll{return (x-y+mod)%mod;};
    auto mul=[&](ll x,ll y)->ll{return (x*y)%mod;};
    vector<ll> inv(N+1,1);
    for(int i=2;i<=N;i++) inv[i]=mod-mul(mod/i,inv[mod%i]);
    int sz=1;
    for(int i=1;i<=n;i++) sz*=3;
    vector<ll> p(sz,1); //P(1->2)
    auto h_id=[&](vector<int> v)->int
    {
        int h=0;
        for(int x:v) h=3*h+x;
        return h;
    };
    auto f=[&](int i,int j)->ll{return mul(a[i],inv[a[i]+a[j]]);};
    vector<int> now(n,0);
    function<void(int)> gen=[&](int idx)
    {
        if(idx==n)
        {
            int x=-1;
            for(int i=0;i<n;i++) if(now[i]==2) x=i;
            if(x!=-1)
            {
                vector<int> prv=now;
                prv[x]=0;
                ll r=p[h_id(prv)];
                for(int i=0;i<n;i++) if(now[i]==1) r=mul(r,f(i,x));
                p[h_id(now)]=r;
            }
            return;
        }
        for(int i=0;i<3;i++)
        {
            now[idx]=i;
            gen(idx+1);
        }
    };
    gen(0);
    vector<ll> not_scc((1<<n),0);
    vector<ll> scc((1<<n),0);
    for(int m=1;m<(1<<n);m++)
    {
        for(int s=(m-1)&m;s>0;s=(s-1)&m)
        {
            vector<int> t(n);
            for(int i=0;i<n;i++)
            {
                if(s&(1<<i)) t[i]=1;
                else if(m&(1<<i)) t[i]=2;
            }
            not_scc[m]=add(not_scc[m],mul(p[h_id(t)],scc[s]));
        }
        scc[m]=sub(1,not_scc[m]);
    }
    vector<ll> dp((1<<n),0);
    dp[0]=1;
    ll res=0;
    for(int m=1;m<(1<<n);m++)
    {
        dp[m]=add(dp[m],scc[m]);
        for(int s=(m-1)&m;s>0;s=(s-1)&m) //s becomes head
        {
            vector<int> t(n);
            for(int i=0;i<n;i++)
            {
                if(s&(1<<i)) t[i]=1;
                else if(m&(1<<i)) t[i]=2;
            }
            ll r=mul(scc[s],mul(dp[m^s],p[h_id(t)]));
            dp[m]=add(dp[m],r);
            if(m==(1<<n)-1) res=add(res,mul(__builtin_popcount(s),r));
        }
    }
    res=add(res,mul(n,scc[(1<<n)-1]));
    cout << res << "\n";
    return 0;
}