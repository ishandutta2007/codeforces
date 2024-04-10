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

    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0]=0;
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i])
            s.erase(a[i]);
    }

    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
            res[i]=a[i];
        else
        {
            int x=*(s.begin());
            s.erase(x);
            res[i]=x;
        }
    }

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}