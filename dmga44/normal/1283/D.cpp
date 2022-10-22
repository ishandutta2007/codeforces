#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x;
    cin >> n >> m;
    vector<int> xs(n);
    map<int,bool> mk;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        mk[x]=1;
        xs[i]=x;
    }
    queue<pii> q;
    for(int i=0;i<n;i++)
    {
        x=xs[i];
        if(!mk[x-1])
        {
            mk[x-1]=1;
            q.push(pii(x-1,1));
        }
        if(!mk[x+1])
        {
            mk[x+1]=1;
            q.push(pii(x+1,1));
        }
    }

    ll res=0,cant=0;
    vector<int> pos;
    while(cant<m)
    {
        pii xx=q.front();
        int d=xx.second;
        int u=xx.f;
        q.pop();

        res+=d;
        pos.push_back(u);
        cant++;
        if(!mk[u-1])
        {
            mk[u-1]=1;
            q.push(pii(u-1,d+1));
        }
        if(!mk[u+1])
        {
            mk[u+1]=1;
            q.push(pii(u+1,d+1));
        }
    }

    db(res)
    for(int i=0;i<m;i++)
        cout << pos[i] << ' ';
    cout << '\n';

    return 0;
}