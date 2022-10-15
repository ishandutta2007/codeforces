#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll CNT=10000;
ll ans[CNT],cnt=0;

void bkt(ll strat,ll cur)
{
    ans[++cnt]=cur;
    if(strat==11)
        return;
    bkt(strat+1,cur*10+4);
    bkt(strat+1,cur*10+7);
}

ll prefix(ll poz)
{
    ll sol=0;
    ll lst=0;
    for(ll i=1;i<CNT;i++)
    {
        ll cur=min(poz,ans[i]);
        sol+=(ll)(cur-lst)*ans[i];
        lst=cur;
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bkt(0,0);
    sort(ans+1,ans+cnt+1);
    ll st,dr;
    cin>>st>>dr;
    cout<<prefix(dr)-prefix(st-1)<<"\n";
    return 0;
}
/**

**/