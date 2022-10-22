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
#define MAXN (ll)(1e3+5)

string s[MAXN];

int32_t main()
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
        bool ok=0;
        pii kk;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(s[i][j]==s[j][i])
                {
                    ok=1;
                    kk=pii(i,j);
                }
        if(ok)
        {
            db("YES")
            for(int i=0;i<=m;i++)
            {
                if(i&1)
                    cout << kk.f+1 << ' ';
                else
                    cout << kk.s+1 << ' ';
            }
            cout << '\n';
            continue;
        }

        if(m&1)
        {
            db("YES")
            for(int i=0;i<=m;i++)
                cout << (i&1)+1 << ' ';
            cout << '\n';
            continue;
        }

        if(n==2)
        {
            db("NO")
            continue;
        }

        db("YES")
        for(int i=0;i<n;i++)
        {
            int hayai=-1;
            int hayad=-1;
            for(int j=0;j<n;j++)
                if(s[i][j]=='a')
                    hayad=j;
            for(int j=0;j<n;j++)
                if(s[j][i]=='a')
                    hayai=j;
            if(hayad!=-1 && hayai!=-1)
            {
                m/=2;
                if(m&1)
                {
                    for(int ii=0;ii<=m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayad+1 << ' ';
                    }
                    for(int ii=0;ii<m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayai+1 << ' ';
                    }
                }
                else
                {
                    for(int ii=0;ii<=m;ii++)
                    {
                        if(ii&1)
                            cout << hayad+1 << ' ';
                        else
                            cout << i+1 << ' ';
                    }
                    for(int ii=0;ii<m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayai+1 << ' ';
                    }
                }
                cout << '\n';
                break;
            }

            hayad=-1;
            hayai=-1;
            for(int j=0;j<n;j++)
                if(s[i][j]=='b')
                    hayad=j;
            for(int j=0;j<n;j++)
                if(s[j][i]=='b')
                    hayai=j;
            if(hayad!=-1 && hayai!=-1)
            {
                m/=2;
                if(m&1)
                {
                    for(int ii=0;ii<=m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayad+1 << ' ';
                    }
                    for(int ii=0;ii<m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayai+1 << ' ';
                    }
                }
                else
                {
                    for(int ii=0;ii<=m;ii++)
                    {
                        if(ii&1)
                            cout << hayad+1 << ' ';
                        else
                            cout << i+1 << ' ';
                    }
                    for(int ii=0;ii<m;ii++)
                    {
                        if(ii&1)
                            cout << i+1 << ' ';
                        else
                            cout << hayai+1 << ' ';
                    }
                }
                cout << '\n';
                break;
            }
        }
    }

    return 0;
}
/**
3
3 1
*aa
b*a
bb*
3 2
*aa
b*a
bb*
3 3
*aa
b*a
bb*
**/