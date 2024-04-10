#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN (10000005ll)

ll p[MAXN][2];
ll f[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a[i]=x;
        if(f[x]<2)
            p[x][f[x]]=i;
        f[x]++;
    }

    ll res=MAXN*MAXN;
    pii rrr=pii(0,0);
    for(ll i=1;i<MAXN;i++)
    {
        if(f[i]>=2)
        {
            if(res>i)
            {
                res=i;
                rrr=pii(p[i][0],p[i][1]);
            }
            continue;
        }
        ll ant=-1;
        for(ll j=i;j<MAXN;j+=i)
        {
            if(!f[j])
                continue;
            if(ant!=-1)
            {
                if(res>(a[ant]*j)/i)
                {
                    res=(a[ant]*j)/i;
                    rrr=pii(ant,p[j][0]);
                }
                break;
            }
            else
                ant=p[j][0];
        }
    }
    if(rrr.first>rrr.second)
        swap(rrr.first,rrr.second);
    cout << rrr.first+1 << ' ' << rrr.second+1 << '\n';

    return 0;
}