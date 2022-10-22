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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> mki(n),mko(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        if(a[i]!=-1)
        {
            mki[a[i]]=1;
            mko[i]=1;
        }
    }

    vector<int> vv;
    vector<int> pn;
    for(int i=0;i<n;i++)
    {
        if(!mko[i])
            vv.push_back(i);
        else if(!mki[i])
            pn.push_back(i);
    }
//    db(vv.size())
    int pos=0;
    for(int i=0;i<vv.size();i++)
    {
        int u=vv[i];
        int v=vv[(i+1)%vv.size()];
        if(!mki[v])
            a[u]=v;
        else
        {
            a[u]=pn[pos];
            pos++;
        }
    }

    for(int i=0;i<n;i++)
        cout << a[i]+1 << ' ';
    cout << '\n';

    return 0;
}