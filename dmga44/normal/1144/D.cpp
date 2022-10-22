#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

int f[MAXN],a[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }

    x=-1;
    for(int i=0;i<MAXN;i++)
        if(x==-1 || f[x]<f[i])
            x=i;

    int ini=-1;
    for(int i=0;i<n;i++)
        if(ini==-1 && a[i]==x)
            ini=i;
    db(n-f[x])
    for(int i=ini-1;i>=0;i--)
    {
        if(a[i]>x)
            cout << 2 << ' ' << i+1 << ' ' << i+2 << '\n';
        else
            cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
        a[i]=x;
    }

    for(int i=ini+1;i<n;i++)
    {
        if(a[i]>x)
            cout << 2 << ' ' << i+1 << ' ' << i << '\n';
        else if(a[i]<x)
            cout << 1 << ' ' << i+1 << ' ' << i << '\n';
        a[i]=x;
    }

    return 0;
}