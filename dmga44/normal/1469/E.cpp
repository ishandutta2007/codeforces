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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<20)

bool mk[MAXN];
int sum[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int extra=max(0,k-20);
        k=min(k,20);
        int res=-1;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
            sum[i+1]=sum[i]+s[i]-'0';
        for(int i=0;i+extra+k<=n;i++)
        {
            int mask=0;
            for(int j=0;j<k;j++)
                if(s[i+extra+k-j-1]=='1')
                    mask|=(1<<j);
            mk[(1<<k)-1-mask]|=(1&(sum[i+extra]-sum[i]==extra));
        }

        for(int i=0;i<(1<<k);i++)
            if(!mk[i])
            {
                res=i;
                break;
            }
        for(int i=0;i+extra+k<=n;i++)
        {
            int mask=0;
            for(int j=0;j<k;j++)
                if(s[i+extra+k-j-1]=='1')
                    mask|=(1<<j);
            mk[(1<<k)-1-mask]=0;
        }

        if(res==-1)
            db("NO")
        else
        {
            db("YES")
            for(int i=0;i<extra;i++)
                cout << '0';
            for(int j=0;j<k;j++)
                cout << "01"[(bool)(res&(1<<(k-j-1)))];
            cout << '\n';
        }
    }

    return 0;
}