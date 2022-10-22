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

    string s;
    cin >> s;
    vector<char> v;
    int n=s.size();
    for(int i=0;i<n/4;i++)
    {
        int f[3];
        for(int j=0;j<3;j++)
            f[j]=0;
        f[s[i*2]-'a']++;
        f[s[i*2+1]-'a']++;
        f[s[n-i*2-1]-'a']++;
        f[s[n-i*2-2]-'a']++;
        for(int j=0;j<3;j++)
            if(f[j]==2)
            {
                v.push_back('a'+j);
                break;
            }
    }

    for(auto y : v)
        cout << y;
    if(n%4)
        cout << s[n/2];

    reverse(v.begin(),v.end());
    for(auto y : v)
        cout << y;
    db("")

    return 0;
}