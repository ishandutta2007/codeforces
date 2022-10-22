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
#define MAXN (ll)(5e2+5)

string s[MAXN];

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
        for(int i=0;i<n;i++)
            cin >> s[i];
        int p=1;
        if(m%3==1)
            p=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(j%3==p)
                    s[i][j]='X';
        for(int i=p;i+2<m;i+=3)
        {
            bool done=0;
            for(int j=0;j<n;j++)
            {
                if(s[j][i+1]=='X' && !done)
                {
                    done=1;
                    s[j][i+2]='X';
                }
                if(s[j][i+2]=='X' && !done)
                {
                    done=1;
                    s[j][i+1]='X';
                }
            }
            if(!done)
            {
                s[0][i+1]='X';
                s[0][i+2]='X';
            }
        }

        for(int i=0;i<n;i++)
            db(s[i])
    }

    return 0;
}