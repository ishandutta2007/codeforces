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
#define MAXN 1005

ll a[MAXN][MAXN],ac[MAXN][MAXN],n,m;

ll solve(ll x,ll y)
{
    ll x1=x/n;
    ll y1=y/m;
    ll xx=x%n;
    ll yy=y%m;
    ll res=0;
    res+=(2*((x1/2)*(y1/2))*(n*m));
    int xy=x1^y1;
    int f=__builtin_popcount(xy);
    int ok=1-(f&1);
//    db(ok)
    if(x1 && y1)
    {
        if(x1&1)
            res+=(y1/2)*(n*m);
        if(y1&1)
            res+=(x1/2)*(n*m);
        if(x1&1 && y1&1 && ok)
            res+=ac[n][m];
        else if(x1&1 && y1&1)
            res+=(n*m)-ac[n][m];
    }

//    cout << res << '\n';
    res+=((x1/2)*n)*yy;
    res+=((y1/2)*m)*xx;

//    x1++,y1++;
    if(ok)
    {
        res+=ac[xx][yy];
        if(x1&1)
            res+=(n*yy)-ac[n][yy];
        if(y1&1)
            res+=(m*xx)-ac[xx][m];
    }
    else
    {
        res+=((xx*yy)-ac[xx][yy]);
        if(x1&1)
            res+=ac[n][yy];
        if(y1&1)
            res+=ac[xx][m];
    }
//    cout << x << ' ' << y << '\n';
//    db(res)
//    db("")
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> m >> q;
    string s[n];
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[i][j]=(s[i][j]=='1');
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ac[i+1][j+1]=(ac[i][j+1]+ac[i+1][j]-ac[i][j]+a[i][j]);

    while(q--)
    {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        db(solve(x2,y2)-solve(x1-1,y2)-solve(x2,y1-1)+solve(x1-1,y1-1))
//        db("")
    }

    return 0;
}
/**
2 2 1
10
11
1 1 8 8
**/