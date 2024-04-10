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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int f[MAXN];
int pos[MAXN];
vector<string> act[MAXN];
set<int> posibles;
bool mk[MAXN];

int trans(string& s)
{
    ll v=0;
    for(int i=0;i<s.size();i++)
    {
        v*=27;
        if(s[i]=='_')
            v+=26;
        else
            v+=(s[i]-'a');
    }
    return v;
}

void mkk(string& s,int v)
{
    string cpy=s;
    for(int i=0;i<(1<<s.size());i++)
    {
        for(int j=0;j<s.size();j++)
            if(i&(1<<j))
                s[j]='_';
        f[trans(s)]+=v;
        if(v==-1 && f[trans(s)]==act[pos[trans(s)]-1].size() && pos[trans(s)])
            posibles.insert(trans(s));
        s=cpy;
    }
}

set<int> mkk2(string& s)
{
    set<int> res;
    string cpy=s;
    for(int i=0;i<(1<<s.size());i++)
    {
        for(int j=0;j<s.size();j++)
            if(i&(1<<j))
                s[j]='_';
        res.insert(trans(s));
        s=cpy;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
//        db(trans(s))
        pos[trans(s)]=i+1;
    }

    vector<int> res;

    for(int i=0;i<m;i++)
    {
        string kk;
        int p;
        cin >> kk >> p;
        p--;
        act[p].push_back(kk);
        mkk(kk,1);
    }

    for(int i=0;i<MAXN;i++)
        if(f[i]==act[pos[i]-1].size() && pos[i])
            posibles.insert(i);
//    for(auto y : posibles)
//        cout << y << ' ' << pos[y] << '\n';
//        db()

    while(1)
    {
        if(posibles.empty())
            break;
        int i=*posibles.begin();
        posibles.erase(i);
        if(mk[i])
            continue;
        res.push_back(pos[i]);
        mk[i]=1;

        i=pos[i]-1;
//        db("")
//        db(i)
        if(act[i].size())
            for(auto sss : act[i])
                mkk(sss,-1);
    }

    if(res.size()<n)
    {
        db("NO")
        return 0;
    }

    db("YES")
    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
/**
5 3 4
_b_d
__b_
aaaa
ab__
_bcd
abcd 4
abba 2
dbcd 5
**/