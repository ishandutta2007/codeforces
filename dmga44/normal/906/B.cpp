#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pi acos(-1)
#define MAXN 100005

vector<int> adj[MAXN];
vector<vector<int> > a;

bool check(int n,int m,vector<int> v)
{
    bool ok=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            a[i][j]=v[i*m+j];
            for(auto v : adj[a[i][j]])
            {
                if(i)
                    ok&=(v!=a[i-1][j]);
                if(j)
                    ok&=(v!=a[i][j-1]);
            }
        }
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        {
            a.push_back(vector<int>(m));
            for(int j=0;j<m;j++)
            {
                a[i][j]=i*m+j;
                if(j)
                {
                    adj[a[i][j]].push_back(a[i][j-1]);
                    adj[a[i][j-1]].push_back(a[i][j]);
                }
                if(i)
                {
                    adj[a[i][j]].push_back(a[i-1][j]);
                    adj[a[i-1][j]].push_back(a[i][j]);
                }
            }
        }

    if(n*m==1)
    {
        db("YES")
        db(1)
        return 0;
    }
    if(n*m<=10)
    {
        vector<int> per;
        for(int i=0;i<n*m;i++)
            per.push_back(i);

        bool ok=0;
        while(!ok && next_permutation(all(per)))
            ok=check(n,m,per);

        if(ok)
        {
            db("YES")
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout << per[i*m+j]+1 << ' ';
                cout << '\n';
            }
        }
        else
            db("NO")
    }
    else
    {
        while(1)
        {
            ordered_set s;
            for(int i=0;i<n*m;i++)
                s.insert(i);
            for(int i=0;i<n*m-8;i++)
            {
                bool ok=0;
                while(!ok)
                {
                    ok=1;
                    ll p1=rand();
                    ll p2=rand();
                    int pos=(p1*(1ll<<17)+p2)%(n*m-i);
                    ll x=*s.find_by_order(pos);
                    for(auto v : adj[x])
                    {
                        if(i/m)
                            ok&=(v!=a[(i/m)-1][i%m]);
                        if(i%m)
                            ok&=(v!=a[(i/m)][(i%m)-1]);
                    }

                    if(ok)
                    {
                        a[i/m][i%m]=x;
                        s.erase(x);
                    }
                }
            }
            vector<int> per;
            for(int i=0;i<8;i++)
                per.push_back(*s.find_by_order(i));
            do{
                bool ok=1;
                for(int i=n*m-8;i<n*m;i++)
                {
                    int x=per[i-(n*m-8)];
                    a[i/m][i%m]=x;
                    for(auto v : adj[x])
                    {
                        if(i/m)
                            ok&=(v!=a[(i/m)-1][i%m]);
                        if(i%m)
                            ok&=(v!=a[(i/m)][(i%m)-1]);
                    }
                }
                if(ok)
                {
                    db("YES")
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                            cout << a[i][j]+1 << ' ';
                        cout << '\n';
                    }
                    return 0;
                }
            }while(next_permutation(all(per)));

        }
    }

    return 0;
}