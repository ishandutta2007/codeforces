#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

ll p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k,res=0;
    cin >> n >> m >> k;
    for(ll i=0;i<m;i++)
        cin >> p[i];

    ll pos=((p[0]-1)/k+1)*k,l=0,add=0;
    while(l<m)
    {
//        db(pos)
        res++;
        ll pl=0;
        while(l<m && p[l]<=pos)
        {
            l++;
            pl++;
        }
        add+=pl;

        if(l<m && p[l]<=pos+pl)
            pos=pos+pl;
        else if(l<m)
            pos=((p[l]-1-add)/k+1)*k+add;
    }
    db(res)

    return 0;
}