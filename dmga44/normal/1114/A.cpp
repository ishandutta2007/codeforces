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

    int x,y,z;
    cin >> x >> y >> z;
    int a,b,c;
    cin >> a >> b >> c;
    if(x<=a)
    {
        a-=x;
        if(y<=a+b)
        {
            int mi=min(y,a);
            a-=mi;
            y-=mi;
            b-=y;
            if(z<=a+b+c)
                db("YES")
            else
                db("NO")
        }
        else
            db("NO")
    }
    else
        db("NO")

    return 0;
}