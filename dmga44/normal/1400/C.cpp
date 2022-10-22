#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(4e18)
#define pi acos(-1)
#define MAXN (ll)(1e5+20)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n=s.size();
        string res;
        res.resize(n);
        for(int i=0;i<n;i++)
        {
            int r=1;
            if(i+x<n && s[i+x]=='0')
                r=0;
            if(i-x>=0 && s[i-x]=='0')
                r=0;
            res[i]=r+'0';
        }
        string kk;
        kk.resize(n);
        for(int i=0;i<n;i++)
        {
            int r=0;
            if(i+x<n && res[i+x]=='1')
                r=1;
            if(i-x>=0 && res[i-x]=='1')
                r=1;
            kk[i]=r+'0';
        }

        bool ok=1;
        for(int i=0;i<n;i++)
            ok&=(kk[i]==s[i]);
        if(!ok)
            db(-1)
        else
            db(res)
    }

    return 0;
}