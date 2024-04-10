#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
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

    ll k;
    cin >> k;
    if(k==1)
    {
        db(3)
        cout << "2 -3 2\n";
        return 0;
    }
    int ok=0;
    for(int i=1;i<1000;i++)
    {
        int a=(2*i-(k+i)%(2*i))%(2*i);
        if((k+2*i*i+i+2*a*i+a)/(2*i)<=1000000)
        {
            int x=(k+2*i*i+i+2*a*i+a)/(2*i);
            vector<int> res(2*i+1);
            int n=2*i+1;
            db(n)
            for(int j=1;j<n;j+=2)
                res[j]=-1;
            res[n-2]-=a;
            res[n-1]=x;
            for(auto y : res)
                cout << y << ' ';
            cout << '\n';
            ok=1;
            break;
        }
    }
    if(!ok)
        db(-1)

    return 0;
}