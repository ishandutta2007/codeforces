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
#define MAXN 100005

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y;
    cin >> n;
    vector<pii> ps;
    for(int i=0;i<4*n+1;i++)
    {
        cin >> x >> y;
        ps.push_back(pii(x,y));
    }

    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            for(int u=i+1;u<=50;u++)
                for(int k=j+1;k<=50;k++)
                {
                    int xx=0;
                    for(auto y : ps)
                        if((y.first==i || y.first==u || y.second==j || y.second==k)
                           && (i<=y.first && y.first<=u && j<=y.second && y.second<=k))
                            xx++;
                    if(xx==4*n)
                    {
                        for(auto y : ps)
                            if(!((y.first==i || y.first==u || y.second==j || y.second==k)
                           && (i<=y.first && y.first<=u && j<=y.second && y.second<=k)))
                            {
                                cout<< y.first << ' ' << y.second << '\n';
                                return 0;
                            }
                    }
                }

    return 0;
}