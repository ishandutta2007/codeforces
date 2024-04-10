#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=10000;
ll ans[N],cnt=0;

void bkt(ll strat,ll cur)
{
    ans[++cnt]=cur;
    if(strat==10)
        return;
    bkt(strat+1,cur*10+4);
    bkt(strat+1,cur*10+7);
}

ll fact(ll x)
{
    ll ans=1;
    for(ll i=1;i<=x;i++)
        ans=(ll)ans*i;
    return ans;
}

ll v[100];
bool viz[100];

inline void gt(ll n,ll ind)
{
    for(ll i=1;i<=n;i++)
        viz[i]=0;
    ind--;
    for(ll poz=1;poz<=n;poz++)
    {
        ll nxt=fact(n-poz);
        ll cur=ind/nxt+1;
        ll meet=0;
        ind%=nxt;
        for(ll j=1;j<=n;j++)
            if(viz[j]==0)
            {
                meet++;
                if(meet==cur)
                {
                    viz[j]=1;
                    v[poz]=j;
                    break;
                }
            }
    }
}

inline bool isl(ll x)
{
    while(x)
    {
        ll cif=x%10;
        if(cif!=4 && cif!=7)
            return 0;
        x/=10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bkt(0,0);
    sort(ans+1,ans+cnt+1);
    ll n,k;
    cin>>n>>k;
    if(n<=13 && fact(n)<k)
    {
        cout<<"-1\n";
        return 0;
    }
    ll suf=min(n,13*1LL);
    gt(suf,k);
    ll dr=n-suf;
    ll answer=0;
    for(ll i=1;i<cnt;i++)
    {
        if(ans[i] && ans[i]<=dr)
            answer++;
    }

    for(ll i=1;i<=suf;i++)
    {
        v[i]+=dr;
    }
    for(ll i=1;i<=suf;i++)
    {
        ll ind=i+dr;
        if(isl(ind) && isl(v[i]))
        {
            answer++;
        }
    }
    cout<<answer<<"\n";
    return 0;
    for(ll i=1;i<=suf;i++)
        cout<<v[i];
    return 0;
}
/**

**/