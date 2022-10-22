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

int f[50];

void solve(string s)
{
    int v=s[0]-'0';
    int a=0;
    if(s[1]=='p')
        a=12;
    if(s[1]=='s')
        a=24;
    f[a+v]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    solve(s1);
    solve(s2);
    solve(s3);

    int res=3;
    for(int i=0;i<50;i++)
    {
        res=min(res,3-f[i]);
        if(i>1)
        {
            int cont=0;
            for(int j=i-2;j<=i;j++)
                if(!f[j])
                    cont++;
            res=min(res,cont);
        }
    }
    db(res)

    return 0;
}