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
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e2+5)

string s[MAXN];

struct op{
    vector<pii> ps;
};

void solve3(vector<op>& ans,pii p1,pii p2,pii p3)
{
    op x;
    x.ps.push_back(p1);
    x.ps.push_back(p2);
    x.ps.push_back(p3);
    ans.push_back(x);
}

void solve1(vector<op>& ans,pii p)
{
    op x;
    vector<pii> ps;
    ps.push_back(p);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(pii(i,j)!=p)
                ps.push_back(pii(i,j));
    solve3(ans,ps[0],ps[1],ps[2]);
    solve3(ans,ps[0],ps[1],ps[3]);
    solve3(ans,ps[0],ps[3],ps[2]);
}


void solve2(vector<op>& ans,pii p1,pii p2)
{
    op x;
    vector<pii> ps;
    ps.push_back(p1);
    ps.push_back(p2);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(pii(i,j)!=p1 && pii(i,j)!=p2)
                ps.push_back(pii(i,j));
    solve3(ans,ps[0],ps[3],ps[2]);
    solve3(ans,ps[1],ps[2],ps[3]);
}

void solve(vector<op>& ans)
{
    vector<pii> ts;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(s[i][j]=='1')
                ts.push_back(pii(i,j));
    if(ts.size()==0)
        return ;
    if(ts.size()==3)
    {
        solve3(ans,ts[0],ts[1],ts[2]);
        return ;
    }
    if(ts.size()==1)
    {
        solve1(ans,ts[0]);
        return ;
    }
    if(ts.size()==2)
    {
        solve2(ans,ts[0],ts[1]);
        return ;
    }
    solve2(ans,ts[0],ts[1]);
    solve2(ans,ts[2],ts[3]);
}

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
        vector<op> ans;
        vector<int> is;
        for(int i=1;i<n;i+=2)
            is.push_back(i);
        if(n&1)
            is.push_back(n-1);
        for(auto i : is)
            for(int j=m-1;j>1;j--)
            {
                if(s[i][j]=='0' && s[i-1][j]=='0')
                    continue;
                op x;
                if(s[i][j]=='1')
                    x.ps.push_back(pii(i,j));
                if(s[i-1][j]=='1')
                    x.ps.push_back(pii(i-1,j));
                for(int jj=0;jj<2;jj++)
                    if(x.ps.size()<3)
                        x.ps.push_back(pii(i-jj,j-1));
                ans.push_back(x);
                for(auto p : x.ps)
                    s[p.f][p.s]=('0'+'1'-s[p.f][p.s]);
            }
//        db(ans.size())
        for(int i=n-1;i>1;i--)
        {
            if(s[i][0]=='0' && s[i][1]=='0')
                continue;
            op x;
            if(s[i][0]=='1')
                x.ps.push_back(pii(i,0));
            if(s[i][1]=='1')
                x.ps.push_back(pii(i,1));
            for(int jj=0;jj<2;jj++)
                if(x.ps.size()<3)
                    x.ps.push_back(pii(i-1,jj));
            ans.push_back(x);
            for(auto p : x.ps)
                s[p.f][p.s]=('0'+'1'-s[p.f][p.s]);
        }
//        db(ans.size())

        solve(ans);

        db(ans.size())
        for(auto opp : ans)
        {
            for(auto p : opp.ps)
                cout << p.f+1 << ' ' << p.s+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
/**
5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101

1
3 3
011
101
110
**/