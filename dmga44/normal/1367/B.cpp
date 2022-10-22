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
typedef pair<ld,ld> pdd;
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
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n;
        vector<int> p[2];
        int f[2];
        f[0]=f[1]=0;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            f[a&1]++;
            p[a&1].push_back(i);
        }
        if(f[0]==(n+1)/2 && f[1]==n/2)
        {
            int res=0;
            for(int i=0;i<f[0];i++)
                res+=(p[0][i]&1);
            db(res)
        }
        else
            db(-1)
    }

    return 0;
}