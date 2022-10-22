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
#define MAXN 100005

int a[MAXN],m[105][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int res=0;
    for(int i=0;i<105;i++)
    {
        m[i][1]=-1;
        m[i][0]=105;
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        res+=a[i];
        for(int j=0;j<105;j++)
            m[j][0]=min(m[j][0],a[i]);
        for(int j=1;j<105;j++)
            if((a[i]%j)==0)
                m[j][1]=max(m[j][1],a[i]);
    }

    int r=res;
    for(int i=1;i<105;i++)
        res=min(res,r-(m[i][1]-(m[i][0]*i)+(m[i][0]-m[i][1]/i)));

    db(res)

    return 0;
}