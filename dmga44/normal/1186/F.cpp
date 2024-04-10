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
//#define MAXN 1005
//
//ll a[MAXN][MAXN],ac[MAXN][MAXN],n,m;
//
//ll solve(ll x,ll y)
//{
//    ll x1=x/n;
//    ll y1=y/m;
//    ll xx=x%n;
//    ll yy=y%m;
//    ll res=0;
//    res+=(2*((x1/2)*(y1/2))*(n*m));
//    if(x1 && y1)
//    {
//        if(x1&1)
//            res+=(y1/2)*(n*m);
//        if(y1&1)
//            res+=(x1/2)*(n*m);
//        if(x1&1 && y1&1)
//            res+=ac[n][m];
//    }
//
////    cout << res << '\n';
//    res+=((x1/2)*n)*yy;
//    res+=((y1/2)*m)*xx;
//
//    if(x1&1)
//        res+=ac[n][yy];
//    if(y1&1)
//        res+=ac[xx][m];
////    x1++,y1++;
//    int ok=1;
//    vector<int> vx,vy;
//    if(x1<y1)
//        swap(x1,y1);
//    while(x1)
//    {
//        vx.push_back(x1&1);
//        x1/=2;
//    }
//    while(y1)
//    {
//        vy.push_back(y1&1);
//        y1/=2;
//    }
//    while(vy.size()<vx.size())
//        vy.push_back(0);
//    int p=0;
//    while(p<vx.size())
//    {
////        cout << vx[p] << ' ' << vy[p] << '\n';
//        if(vx[p]!=vy[p])
//            ok=(1-ok);
//        p++;
//    }
////    db(ok)
//    if(ok)
//        res+=ac[xx][yy];
//    else
//        res+=((xx*yy)-ac[xx][yy]);
////    cout << x << ' ' << y << '\n';
////    db(res)
////    db("")
//    return res;
//}
#define MAXN 1000005

int cant[MAXN],f[MAXN];
vector<pii> edges,res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        f[u]++;
        f[v]++;
        cant[u]++;
        cant[v]++;
        edges.push_back(pii(u,v));
    }

    while(1)
    {
        for(int i=0;i<m;i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            if(cant[u]==((f[u]+1)/2) || cant[v]==((f[v]+1)/2))
            {
                res.push_back(edges[i]);
                continue;
            }
            cant[u]--;
            cant[v]--;
        }

        if(res.size()>(n+m+1)/2)
        {
            res.clear();
            for(int i=0;i<n;i++)
                cant[i]=f[i];
            random_shuffle(edges.begin(),edges.end());
        }
        else
        {
            db(res.size())
            for(auto y : res)
                cout << y.first+1 << ' ' << y.second+1 << '\n';
            return 0;
        }
    }
//    int q;
//    cin >> n >> m >> q;
//    string s[n];
//    for(int i=0;i<n;i++)
//        cin >> s[i];
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            a[i][j]=(s[i][j]=='1');
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            ac[i+1][j+1]=(ac[i][j+1]+ac[i+1][j]-ac[i][j]+a[i][j]);
//
//    while(q--)
//    {
//        ll x1,y1,x2,y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        db(solve(x2,y2)-solve(x1-1,y2)-solve(x2,y1-1)+solve(x1-1,y1-1))
//    }

    return 0;
}
/**
2 2 1
10
11
1 1 8 8
**/