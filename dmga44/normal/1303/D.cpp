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

ll ac[32],b[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        for(int i=0;i<30;i++)
            b[i]=0;
        ll n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            int p=0;
            while(x%2==0)
            {
                p++;
                x/=2;
            }
            b[p]++;
        }


        for(int i=0;i<30;i++)
            ac[i+1]=ac[i]+((1ll<<i)*b[i]);

        if(ac[30]<n)
        {
            db(-1)
            continue;
        }
        int res=0;
        for(int i=29;i>=0;i--)
        {
            ll cc=min(b[i],n/(1ll<<i));
            n-=cc*(1ll<<i);
            if(ac[i]<n)
            {
                res++;
                b[i-1]+=2;
            }
        }
        db(res)
    }

    return 0;
}
/**
1
7 1
8
**/