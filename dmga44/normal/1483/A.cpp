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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> f(n);
        vector<vector<int>> avs;
        for(int i=0;i<m;i++)
        {
            vector<int> ks;
            int k;
            cin >> k;
            for(int j=0;j<k;j++)
            {
                int a;
                cin >> a;
                a--;
                ks.push_back(a);
            }
            avs.push_back(ks);
            f[ks[0]]++;
        }

        int tar=-1;
        for(int i=0;i<n;i++)
            if(f[i]>(m+1)/2)
                tar=i;
        for(int i=0;i<m && tar!=-1;i++)
        {
            if(avs[i][0]==tar && avs[i].size()>1 && f[tar]>(m+1)/2)
            {
                f[tar]--;
                swap(avs[i][0],avs[i][1]);
            }
        }

        if(tar!=-1 && f[tar]>(m+1)/2)
            db("NO")
        else
        {
            db("YES")
            for(int i=0;i<m;i++)
                cout << avs[i][0]+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}