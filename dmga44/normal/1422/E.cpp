#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

string res[MAXN];
int sz[MAXN];

string solve(string& s)
{
    string res;
    if(s.size()<=10)
    {
        res=s;
        reverse(all(res));
    }
    else
    {
        res.resize(10);
        for(int i=0;i<5;i++)
            res[i]=s[s.size()-i-1];
        for(int i=5;i<8;i++)
            res[i]='.';
        for(int i=8;i<10;i++)
            res[i]=s[9-i];
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<pii> dec;
    int cant=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(i && s[i]!=s[i-1])
        {
            dec.push_back(pii(s[i-1],cant));
            cant=0;
        }
        cant++;
    }
    dec.push_back(pii(s.back(),cant));

    reverse(all(dec));

    string ac="";
    int cont=0;
    int last[2];
    last[0]=last[1]=0;
    for(int i=0;i<dec.size();i++)
    {
        int t=dec[i].f;
        int ini=ac.size();
        bool pon=0;
        for(int j=1;j<=dec[i].s;j++)
        {
            if(t==last[0])
            {
                if(t>last[1])
                {
                    if(ac.size()==ini+1)
                    {
                        ac.pop_back();
                        pon=0;
                    }
                    else
                    {
                        ac.push_back(dec[i].f);
                        pon=1;
                    }
                }
                if(t<last[1])
                {
                    ac.push_back(dec[i].f);
                    pon=1;
                }
            }
            else if(t>last[0])
            {
                if(ac.size()==ini+1)
                {
                    ac.pop_back();
                    pon=0;
                }
                else
                {
                    ac.push_back(dec[i].f);
                    pon=1;
                }
            }
            else
            {
                ac.push_back(dec[i].f);
                pon=1;
            }
            res[cont]=solve(ac);
            sz[cont]=ac.size();
            cont++;
        }
        if(last[0]!=t && pon)
        {
            last[1]=last[0];
            last[0]=t;
        }
    }

    for(int i=0;i<n;i++)
        cout << sz[n-i-1] << ' ' << res[n-i-1] << '\n';

    return 0;
}