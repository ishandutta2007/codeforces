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
#define MAXN 200005

int a[MAXN],res[MAXN][0];
int vals[MAXN][2][2];
int d[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vals[0][0][0]=MAXN;
    vals[0][0][1]=-1;
    vals[0][1][0]=MAXN;
    vals[0][1][1]=-1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>vals[i][0][1] || a[i]>vals[i][1][1])
        {
            vals[i+1][1][1]=a[i];
            if(a[i]>vals[i][0][1] && a[i]>vals[i][1][1])
            {
                vals[i+1][1][0]=max(vals[i][0][0],vals[i][1][0]);
                if(vals[i][0][0]>vals[i][1][0])
                    d[i+1][1]=0;
                else
                    d[i+1][1]=1;
            }
            else if(a[i]>vals[i][0][1])
            {
                vals[i+1][1][0]=vals[i][0][0];
                d[i+1][1]=0;
            }
            else
            {
                vals[i+1][1][0]=vals[i][1][0];
                d[i+1][1]=1;
            }
        }
        else
        {
            vals[i+1][1][1]=MAXN;
            vals[i+1][1][0]=-1;
            d[i+1][1]=-1;
        }

        if(a[i]<vals[i][0][0] || a[i]<vals[i][1][0])
        {
            vals[i+1][0][0]=a[i];
            if(a[i]<vals[i][0][0] && a[i]<vals[i][1][0])
            {
                vals[i+1][0][1]=min(vals[i][0][1],vals[i][1][1]);
                if(vals[i][0][1]<vals[i][1][1])
                    d[i+1][0]=0;
                else
                    d[i+1][0]=1;
            }
            else if(a[i]<vals[i][0][0])
            {
                vals[i+1][0][1]=vals[i][0][1];
                d[i+1][0]=0;
            }
            else
            {
                vals[i+1][0][1]=vals[i][1][1];
                d[i+1][0]=1;
            }
        }
        else
        {
            vals[i+1][0][1]=MAXN;
            vals[i+1][0][0]=-1;
            d[i+1][0]=-1;
        }
    }

//    for(int i=0;i<=n;i++)
//        cout << vals[i][0][0] << ' ' << vals[i][0][1] << ' ' << vals[i][1][0] << ' ' << vals[i][1][1] << '\n';
//    db("")
    if(d[n][0]!=-1 || d[n][1]!=-1)
    {
        db("YES")
        vector<int> res;
        if(d[n][0]!=-1)
        {
            int ant=0;
            for(int i=n;i>0;i--)
            {
                res.push_back(ant);
                ant=d[i][ant];
            }
        }
        else
        {
            int ant=1;
            for(int i=n;i>0;i--)
            {
                res.push_back(ant);
                ant=d[i][ant];
            }
        }

        reverse(res.begin(),res.end());

        for(auto y : res)
            cout << 1-y << ' ';
    }
    else
        db("NO")

    return 0;
}