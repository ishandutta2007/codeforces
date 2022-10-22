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
#define MAXN (ll)(3e6+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x,m,a,b;
        cin >> n >> x >> m;
        int l=x,r=x;
        for(int i=0;i<m;i++)
        {
            cin >> a >> b;
            if((a<=l && l<=b) || (a<=r && r<=b))
            {
                l=min(a,l);
                r=max(b,r);
            }
        }
        db(r-l+1)
    }

    return 0;
}