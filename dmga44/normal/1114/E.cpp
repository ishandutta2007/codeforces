#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int n;
    cin >> n;
    int res=-1;
    for(int i=(1<<29);i;i>>=1)
    {
        if(res+i>1e9)
            continue;
        cout << "> " << res+i << '\n';
        cout.flush();
        int x;
        cin >> x;
        if(x)
            res+=i;
    }
    res++;
    ll r1=res;

    vector<ll> vals;
    for(int i=0;i<30;i++)
    {
        ll p=(123454ll*rand()+rand())%n;
        cout << "? " << p+1 << '\n';
        cout.flush();
        int x;
        cin >> x;
        vals.push_back(x);
    }

    ll gcd=0;
    for(int i=0;i<30;i++)
        for(int j=i;j<30;j++)
            gcd=__gcd(gcd,abs(vals[i]-vals[j]));

    cout << "! " << r1-((n-1)*gcd) << ' ' << gcd << '\n';
    cout.flush();

    return 0;
}