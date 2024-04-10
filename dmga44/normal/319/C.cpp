#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define MAXN 100005

ll a[MAXN],b[MAXN],h,g;
pll s[MAXN];

ll calc(ll x,pll y)
{
    return x*y.second+y.first;
}

void add(ll n,ll m)
{
    while(h>1 && ((double)(s[h-2].first-n)/(double)(m-s[h-2].second))<=((double)(s[h-2].first-s[h-1].first)/(double)(s[h-1].second-s[h-2].second))+(1e-9))
        h--;
    s[h]=pll(n,m);
    h++;
}

ll query(ll x)
{
    while(g<h-1 && calc(x,s[g])>=calc(x,s[g+1]))
        g++;
    return calc(x,s[g]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    add(0,b[0]);
    for(int i=1;i<n;i++)
    {
        ll x=query(a[i]);
        add(x,b[i]);
    }

    db(s[h-1].first)

    return 0;
}