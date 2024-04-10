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
#define MAXN 105

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        if(k%3!=0)
        {
            if(n%3)
                db("Alice")
            else
                db("Bob")
        }
        else
        {
            n%=(k+1);
            if(n>k-3)
                db("Alice")
            else if(!(n%3))
                db("Bob")
            else
                db("Alice")
        }
    }

//    int k;
//    cin >> k;
//    for(int i=0;i<MAXN;i++)
//        a[i]=0;
//
//    for(int i=1;i<MAXN;i++)
//    {
//        if(!a[i-1] || (i>1 && !a[i-2]) || (i>=k && !a[i-k]))
//            a[i]=1;
//    }
//
//    for(int i=0;i<MAXN;i++)
//        cout << i << ' ' << a[i] << '\n';

    return 0;
}