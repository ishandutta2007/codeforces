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
#define MAXN (ll)(1e1+5)

int m[MAXN][MAXN];
string base0[99];
string base1[99];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> m[i][j];
    for(int i=0;i<n;i++)
        m[i][i]=1;
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                m[i][j]|=(m[i][k]&m[k][j]);

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << m[i][j];

    map<pii,vector<int>> kks;
    set<pii> kk;
    for(int i=0;i<n;i++)
    {
        int mask=0;
        for(int j=0;j<n;j++)
            if(m[i][j])
                mask|=(1<<j);
        kks[pii(__builtin_popcount(mask),mask)].push_back(i);
        kk.insert(pii(__builtin_popcount(mask),mask));
    }

    int lvl=0;
    vector<int> lvls[n];
    for(auto p : kk)
    {
        lvls[lvl]=kks[p];
        lvl++;
    }

    for(int i=0;i<99;i++)
    {
        base1[i]="##.";
        base0[i]="...";
    }
    for(int i=0;i<99;i++)
        base0[i][1]='#';
    for(int i=0;i<9;i++)
        base0[11*i][2]=base0[11*i+10][2]='#';

    int x=3;
    int y=99;
    int z=3*lvl-2;
    cout << x << ' ' << y << ' ' << z << '\n';
    for(int i=0;i<z;i++)
    {
        int act=(z-i)/3;
        if(i%3==1) ///mid
        {
            string tp[99];
            for(int j=0;j<99;j++)
                tp[j]=base1[j];
            for(int j=0;j<9;j++)
                tp[11*act+j+1][2]='#';
            for(int j=0;j<99;j++)
                db(tp[j])
            db("")
        }
        else if(i%3==0) ///numeros
        {
            string tp[99];
            for(int j=0;j<99;j++)
                tp[j]=base0[j];
            for(auto ns : lvls[act])
                tp[ns][0]='1'+ns;
            for(int j=0;j<act;j++)
                if(m[lvls[act][0]][lvls[j][0]])
                    tp[11*j+act+1][1]='.';
            tp[11*act+1][1]='.';
            for(int j=0;j<99;j++)
                db(tp[j])
            db("")
        }
        else
        {
            string tp[99];
            for(int j=0;j<99;j++)
                tp[j]=base0[j];
            for(int j=0;j<act;j++)
                if(m[lvls[act][0]][lvls[j][0]])
                    tp[11*j+act+1][1]='.';
            tp[11*act+1][1]='.';
            for(int j=0;j<99;j++)
                db(tp[j])
            db("")
        }
    }

    return 0;
}
/**
4
0           1           0           1
0           0           1           0
0           1           0           0
1           0           0           0

4
0           1           0           0
0           0           1           0
0           0           0           1
0           0           0           0

4
0           1           0           0
0           0           0           0
0           1           0           0
1           0           1           0
**/