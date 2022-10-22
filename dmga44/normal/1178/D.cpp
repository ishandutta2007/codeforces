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
#define MAXN 2005

bool p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i*2;j<MAXN;j+=i)
                p[j]=1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n;
    cin >> n;
    vector<pii> res;
    for(int i=0;i<n-1;i++)
        res.push_back(pii(i+1,i+2));
    res.push_back(pii(1,n));
    int i=1;
    while(p[n])
    {
        res.push_back(pii(i,i+(n/2)));
        n++;
        i++;
    }

    db(res.size())
    for(auto y : res)
        cout << y.first << ' ' << y.second << '\n';

    return 0;
}