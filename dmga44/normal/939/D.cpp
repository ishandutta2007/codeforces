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
#define MAXN (ll)(5e5+5)

bool mk[26][26];
vector<int> g[26];
bool mk1[26];
vector<pii> res;

void dfs(int u)
{
    mk1[u]=1;
    for(auto v : g[u])
    {
        if(mk1[v])
            continue;
        res.push_back(pii(u,v));
        dfs(v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int u,v;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            if(!mk[s1[i]-'a'][s2[i]-'a'])
            {
                mk[s1[i]-'a'][s2[i]-'a']=1;
                mk[s2[i]-'a'][s1[i]-'a']=1;
                g[s2[i]-'a'].push_back(s1[i]-'a');
                g[s1[i]-'a'].push_back(s2[i]-'a');
            }
        }
    }

    for(int i=0;i<26;i++)
        if(!mk1[i])
            dfs(i);

    db(res.size())
    for(auto y : res)
        cout << (char)(y.f+'a') << ' ' << (char)(y.s+'a') << '\n';

    return 0;
}