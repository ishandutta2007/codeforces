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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n),b(n),pa(n),pb(n),fs(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        pa[a[i]]=i;
    }

    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        b[i]--;
        pb[b[i]]=i;
    }

    for(int i=0;i<n;i++)
        fs[(pb[i]-pa[i]+n)%n]++;

    int res=0;
    for(int i=0;i<n;i++)
        res=max(res,fs[i]);
    db(res)

    return 0;
}