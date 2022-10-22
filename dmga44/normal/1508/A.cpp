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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

string s;

bool solve(string a,string b)
{
    int a0=0;
    int a1=0;
    int b0=0;
    int b1=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0')
            a0++;
        else
            a1++;
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]=='0')
            b0++;
        else
            b1++;
    }
    s.clear();
    if(min(a0,b0)*2<n && min(a1,b1)*2<n)
        return 0;

    bool f=0;
    if(min(a1,b1)*2>=n)
    {
        f=1;
        for(int i=0;i<n;i++)
        {
            a[i]=('0'+'1'-a[i]);
            b[i]=('0'+'1'-b[i]);
        }
        swap(a0,a1);
        swap(b0,b1);
    }

    int pa=0;
    int pb=0;

    while(pa<n || pb<n)
    {
        int ma=0;
        if(pa<n)
        {
            int x=0;
            while(pa<n && a[pa]=='1')
            {
                pa++;
                x++;
            }
            ma=x;
        }
        if(pb<n)
        {
            int x=0;
            while(pb<n && b[pb]=='1')
            {
                pb++;
                x++;
            }
            ma=max(ma,x);
        }

        for(int i=0;i<ma;i++)
            s.push_back('1');
        if(pa<n || pb<n)
        {
            s.push_back('0');
            if(pa<n)
                pa++;
            if(pb<n)
                pb++;
        }
    }

    if(f)
    {
        for(int i=0;i<s.size();i++)
        {
            s[i]=('0'+'1'-s[i]);
        }
    }

    return 1;
}

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
        string a,b,c;
        cin >> a >> b >> c;
        string ans="";
        if(solve(a,b))
            ans=s;
        else if(solve(a,c))
            ans=s;
        else
        {
            solve(b,c);
            ans=s;
        }
        db(ans)
    }

    return 0;
}