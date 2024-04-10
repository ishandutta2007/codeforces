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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0]=='0' || s[n-1]=='0')
        {
            db("NO")
            continue;
        }
        string m1('(',n/2);
        string m2(')',n/2);
        string a=m1+m2;
        string b=m1+m2;
        a="(";
        b="(";
        int cant=0;
        for(int i=0;i<n;i++)
            if(s[i]=='0')
                cant++;
        if(cant&1)
        {
            db("NO")
            continue;
        }
        int cont=0;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                if(i-cont<(n-cant)/2)
                {
                    a.push_back('(');
                    b.push_back('(');
                }
                else
                {
                    a.push_back(')');
                    b.push_back(')');
                }
            }
            else
            {
                if(cont&1)
                {
                    a.push_back(')');
                    b.push_back('(');
                }
                else
                {
                    a.push_back('(');
                    b.push_back(')');
                }
                cont++;
            }
        }
        a.push_back(')');
        b.push_back(')');
        db("YES")
        db(a)
        db(b)
    }

    return 0;
}
/**
3
6
101101
10
1001101101
4
1100
**/