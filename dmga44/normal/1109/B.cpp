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
typedef pair<string,ll> psi;
typedef pair<ll,char> pic;
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

    string s;
    cin >> s;
    bool ok=1;
    int n=s.size();
    for(int i=1;i<n;i++)
        ok&=(s[i]==s[i-1]);
    bool ok2=n&1;
    for(int i=1;i<n/2;i++)
        ok2&=(s[i]==s[i-1]);
    if(ok || ok2)
        db("Impossible")
    else
    {
        bool r=0;
        for(int i=0;i<n-1;i++)
        {
            bool ok=1,ok2=0;
            for(int j=0;j<n/2;j++)
            {
                int p1=(i+1+j)%n;
                int p2=(i-j+n)%n;
                if(s[p1]!=s[p2])
                    ok=0;
                if(s[p1]!=s[j])
                    ok2=1;
            }
            if(ok && ok2)
                r=1;
        }
        if(r)
            db(1)
        else
            db(2)
    }

    return 0;
}