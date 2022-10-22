#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

ll a[MAXN],res[MAXN];
ll n,k;

ll aux(ll i,ll v)
{
    v--;
    return a[i]-3*v*v-3*v-1;
}

ll solve(ll x)
{
    ll ac=0;
    for(int i=0;i<n;i++)
    {
        res[i]=0;
        for(ll po=(1<<29);po;po>>=1)
            if((res[i]+po)<=a[i] && aux(i,res[i]+po)>=x)
                res[i]+=po;
        ac+=res[i];
    }
    return ac;
}

void solve2()
{
    ll ac=0;
    vector<pii> add;
    for(int i=0;i<n;i++)
    {
        ac+=res[i];
        if(res[i]<a[i])
            add.push_back(pii(aux(i,res[i]+1),i));
        else
            add.push_back(pii(-4e18,i));
    }

    sort(allr(add));

    for(ll i=0;i<k-ac;i++)
        res[add[i].second]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll mi=1e9+5;
    for(ll po=(1ll<<61);po;po>>=1)
    {
        ll sum=solve(mi-po);
        if(sum<k)
            mi-=po;
    }
    ll vvv=solve(mi);

    solve2();

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
/**
10 32
1 2 3 4 5 5 5 5 5 5
10 100
10 10 10 10 10 10 10 10 10 10
**/