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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    if(n&1)
    {
        int x=n/2+1;
        for(int i=0;i<x;i++)
            cout << "4";
        for(int i=0;i<x;i++)
            cout << "7";
        cout << '\n';
        return 0;
    }

    int c4=n/2;
    int c7=n/2;
    bool jo=0;
    int pos=0;
    for(int i=0;i<n;i++)
    {
        if((s[i]!='4' || !c4) && (s[i]!='7' || !c7))
        {
            if((s[i]>'4' && !c7) || (s[i]>'7'))
            {
                jo=1;
                break;
            }
            if(s[i]<'4' && c4)
            {
                s[i]='4';
                pos++;
                c4--;
                break;
            }
            if(s[i]<'7' && c7)
            {
                s[i]='7';
                pos++;
                c7--;
                break;
            }
        }
        else
        {
            if(s[i]=='4')
                c4--;
            else
                c7--;
            pos++;
        }
    }

    if(!jo)
    {
        for(int i=pos;i<n;i++)
        {
            if(c4)
            {
                s[i]='4';
                c4--;
            }
            else
                s[i]='7';
        }
        db(s)
    }
    else
    {
        bool hh=0;
        int c4=n/2;
        int c7=n/2;
        for(int i=0;i<pos;i++)
            if(s[i]=='4')
                hh=1;
        if(!hh)
        {
            int x=n/2+1;
            for(int i=0;i<x;i++)
                cout << "4";
            for(int i=0;i<x;i++)
                cout << "7";
            cout << '\n';
            return 0;
        }
        int l4=pos-1;
        for(int i=pos-1;i>=0;i--)
            if(s[i]=='4')
            {
                l4=i;
                break;
            }

        c4=n/2;
        c7=n/2;
        s[l4]='7';
        l4++;
        vector<int> ps4;
        vector<int> ps7;
        for(int i=0;i<l4;i++)
        {
            if(s[i]=='4')
            {
                c4--;
                ps4.push_back(i);
                }
            if(s[i]=='7')
            {
                c7--;
                ps7.push_back(i);
            }
        }
        if(ps7.size()>n/2)
        {
            int p=-1;
            for(int i=(int)(ps4.size())-2;i>=0;i--)
                if(ps4[i+1]-ps4[i]!=1)
                {
                    p=ps4[i];
                    break;
                }
            if(p==-1)
            {
                int x=n/2+1;
                for(int i=0;i<x;i++)
                    cout << "4";
                for(int i=0;i<x;i++)
                    cout << "7";
                cout << '\n';
                return 0;
            }
            l4=p;
            c4=n/2;
            c7=n/2;
            s[l4]='7';
            l4++;
            for(int i=0;i<l4;i++)
            {
                if(s[i]=='4')
                {
                    c4--;
                }
                if(s[i]=='7')
                {
                    c7--;
                }
            }
        }

        for(int i=l4;i<n;i++)
        {
            if(c4)
            {
                s[i]='4';
                c4--;
            }
            else
            {
                s[i]='7';
                c7--;
            }
        }
        db(s)
    }

    return 0;
}