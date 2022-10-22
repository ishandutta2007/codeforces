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
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

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
        int fr=0;
        int fs=0;
        int fp=0;
        for(auto y : s)
        {
            if(y=='R')
                fr++;
            if(y=='S')
                fs++;
            if(y=='P')
                fp++;
        }

        int n=s.size();
        if(fr>fs && fr>fp)
        {
            for(int i=0;i<n;i++)
                cout << "P";
            cout << '\n';
        }
        else if(fp>fs)
        {
            for(int i=0;i<n;i++)
                cout << "S";
            cout << '\n';
        }
        else
        {
            for(int i=0;i<n;i++)
                cout << "R";
            cout << '\n';
        }
    }

    return 0;
}