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
#define MAXN 1005

int a[MAXN][MAXN],res[MAXN][MAXN];
map<int,int> mx[MAXN],my[MAXN];
set<int> xs[MAXN],ys[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,m;
//    cin >> n >> m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
//            cin >> a[i][j];
            scanf("%d",&a[i][j]);
            xs[i].insert(a[i][j]);
            ys[j].insert(a[i][j]);
        }

    for(int i=0;i<n;i++)
    {
        int cont=0;
        for(auto y : xs[i])
        {
            cont++;
            mx[i][y]=cont;
        }
    }

    for(int i=0;i<m;i++)
    {
        int cont=0;
        for(auto y : ys[i])
        {
            cont++;
            my[i][y]=cont;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            res[i][j]=max(xs[i].size(),ys[j].size());
            int v1=ys[j].size()+mx[i][a[i][j]]-my[j][a[i][j]];
            int v2=xs[i].size()+my[j][a[i][j]]-mx[i][a[i][j]];
            res[i][j]=max(res[i][j],max(v1,v2));
//            cout << res[i][j] << ' ';
            printf("%d ",res[i][j]);
        }
        printf("\n");
//        cout << '\n';
    }
    return 0;
}