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
typedef pair<ll,ll> pii;
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
#define MAXN (ll)(1e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<bool> mk(m+1);
    vector<int> ans(m+1,-1);
    vector<int> aux(m+1);
    mk[0]=1;
    for(int i=0;i<n;i++)
    {
//        for(int i=0;i<=m;i++)
//            cout << ans[i] << ' ';
//        cout << '\n';
        ll t,x,y;
        cin >> t >> x >> y;
        for(int j=0;j<m;j++)
        {
            aux[j]=1e6;
            if(mk[j])
                aux[j]=0;
        }
        for(int j=0;j<m;j++)
        {
            if(!mk[j] || aux[j]==y)
                continue;
            ll nex;
            if(t==1)
                nex=j+(x/(int)1e5)+(x%((int)1e5)!=0);
            else
            {
                nex=x*j;
                nex=nex/(int)(1e5)+(nex%((int)1e5)!=0);
            }
            if(nex<=m)
            {
                if(!mk[nex])
                {
                    mk[nex]=1;
                    ans[nex]=i+1;
                }
                aux[nex]=min(aux[nex],aux[j]+1);
            }
        }
    }

    for(int i=1;i<=m;i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}