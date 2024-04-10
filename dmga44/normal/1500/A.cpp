#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2.5e6+5)

vector<int> pos[MAXN];
vector<pii> posss[MAXN*2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> aa;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        pos[a].push_back(i);
    }

    vector<int> p2;
    vector<int> p4;
    for(int i=0;i<MAXN;i++)
    {
        if(pos[i].size()>3)
            p4.push_back(i);
        if(pos[i].size()>1)
        {
            posss[i+i].push_back(pii(pii(pos[i][0],pos[i][1])));
            p2.push_back(i);
        }
        if(pos[i].size())
            aa.push_back(pii(i,pos[i][0]));
    }

    if(p2.size()>1)
    {
        db("YES")
        cout << pos[p2[0]][0]+1 << ' ' << pos[p2[1]][0]+1 << ' ' << pos[p2[0]][1]+1 << ' ' << pos[p2[1]][1]+1 << '\n';
        return 0;
    }
    if(p4.size())
    {
        db("YES")
        cout << pos[p4[0]][0]+1 << ' ' << pos[p4[0]][1]+1 << ' ' << pos[p4[0]][2]+1 << ' ' << pos[p4[0]][3]+1 << '\n';
        return 0;
    }

    sort(all(aa));

    for(int i=0;i<min(4000,(int)aa.size());i++)
        for(int j=i+1;j<min(4000,(int)aa.size());j++)
            posss[aa[i].f+aa[j].f].push_back(pii(aa[i].s,aa[j].s));


    for(int i=0;i<2*MAXN;i++)
    {
        if(posss[i].size()>1)
        {
            db("YES")
            cout << posss[i][0].f+1 << ' ' << posss[i][0].s+1 << ' ' << posss[i][1].f+1 << ' ' << posss[i][1].s+1 << '\n';
            return 0;
        }
    }
    db("NO")

    return 0;
}