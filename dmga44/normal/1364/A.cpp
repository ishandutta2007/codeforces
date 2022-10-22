#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,x;
        cin >> n >> x;
        vector<int> a(n),ac(n+1);
        int pos=-1;
        ll res=-1;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            ac[i+1]=ac[i]+a[i];
            if(pos==-1 && ac[i+1]%x)
                pos=i;
            if(ac[i+1]%x)
                res=i+1;
            else if(pos!=-1)
                res=max(res,(ll)i-pos);
        }
        db(res)
    }

    return 0;
}