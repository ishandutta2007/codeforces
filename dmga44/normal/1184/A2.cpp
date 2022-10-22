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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    bool tt=0;
    for(int i=0;i<n;i++)
        if(s[i]=='1')
            tt=1;
    if(!tt)
    {
        db(n)
        return 0;
    }

    map<int,bool> m;
    for(int i=1;i<n;i++)
        if(n%i==0)
        {
            vector<int> v(i);
            for(int j=0;j<i;j++)
                v[j]=0;
            for(int j=0;j<n;j++)
                if(s[j]=='1')
                    v[j%i]++;
            bool ok=1;
            for(int j=0;j<i;j++)
                if(v[j]&1)
                    ok=0;
            m[i]=ok;
        }

    int res=0;
    for(int i=1;i<n;i++)
        res+=m[__gcd(i,n)];
    db(res)

    return 0;
}