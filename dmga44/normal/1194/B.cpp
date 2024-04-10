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
#define MAXN 50005

int ns[MAXN],ms[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<char> c[n+1];
        vector<char> x(m);
        for(int i=0;i<n;i++)
            c[i]=x;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> c[i][j];
                if(c[i][j]=='*')
                {
                    ns[i]++;
                    ms[j]++;
                }
            }

        int res=n+m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='*')
                    res=min(res,n+m-ns[i]-ms[j]);
                else
                    res=min(res,n+m-ns[i]-ms[j]-1);
            }

        for(int i=0;i<n;i++)
            ns[i]=0;

        for(int i=0;i<m;i++)
            ms[i]=0;

        db(res)
    }

    return 0;
}