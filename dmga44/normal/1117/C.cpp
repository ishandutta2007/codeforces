#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,int> psi;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
string s;
ll x1,y1,x2,y2;

bool check(ll x)
{
    ll div=x/n;
    ll res=x%n;
    ll sx=0,sy=0;
    pii ad;
    for(int i=0;i<n;i++)
    {
        if(i==res)
            ad=pii(sx,sy);
        if(s[i]=='U')
            sy++;
        if(s[i]=='D')
            sy--;
        if(s[i]=='L')
            sx--;
        if(s[i]=='R')
            sx++;
    }

    ll xx=x1+ad.first+sx*div;
    ll yy=y1+ad.second+sy*div;
    if(abs(xx-x2)+abs(yy-y2)<=x)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    cin >> s;

    ll res=-1;
    for(ll i=(1ll<<62);i;i>>=1)
        if(!check(res+i))
            res+=i;
    res++;
    if(res==9223372036854775807)
        db(-1)
    else
        db(res)

    return 0;
}