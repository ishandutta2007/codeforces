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

    ll n,x;
    cin >> n;
    ll sum=0,mul=(n*(n-1))/2;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        sum+=x;
        m[x]++;
    }

    bool res=1;
    int cant=0,v;
    for(auto y : m)
    {
        if(y.second>2)
            cant=2;
        if(y.second==2)
        {
            cant++;
            v=y.first;
        }
    }

    if(cant>1)
    {
        db("cslnb")
        return 0;
    }
    if(cant==1)
    {
        if(!v || m[v-1])
        {
            db("cslnb")
            return 0;
        }
    }

    ll re=sum-mul;
    if(re&1)
        db("sjfnb")
    else
        db("cslnb")

    return 0;
}