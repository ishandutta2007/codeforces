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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int n;

bool is_scc(vector<int> degrees)
{
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=degrees[i];
        if(sum==(i*(i+1))/2+(i+1)*(n-i-1))
            return 0;
    }
    return 1;
}

string s[MAXN];
int deg[MAXN];

vector<int> prepare()
{
    vector<int> res;
    for(int i=0;i<n;i++)
        res.push_back(deg[i]);
    sort(allr(res));
    return res;
}

bool is_ok(vector<int> exchange)
{
    for(auto y : exchange)
    {
        for(int i=0;i<n;i++)
        {
            if(i==y)
                continue;
            if(s[i][y]=='0')
            {
                deg[i]++;
                s[i][y]='1';
            }
            else
            {
                deg[i]--;
                s[i][y]='0';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==y)
                continue;
            if(s[y][i]=='0')
            {
                deg[y]++;
                s[y][i]='1';
            }
            else
            {
                deg[y]--;
                s[y][i]='0';
            }
        }
    }

    bool res=is_scc(prepare());

    for(auto y : exchange)
    {
        for(int i=0;i<n;i++)
        {
            if(i==y)
                continue;
            if(s[i][y]=='0')
            {
                deg[i]++;
                s[i][y]='1';
            }
            else
            {
                deg[i]--;
                s[i][y]='0';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==y)
                continue;
            if(s[y][i]=='0')
            {
                deg[y]++;
                s[y][i]='1';
            }
            else
            {
                deg[y]--;
                s[y][i]='0';
            }
        }
    }

    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<n;j++)
            if(s[i][j]=='1')
                deg[i]++;
    }

    if(is_scc(prepare()))
    {
        cout << "0 1\n";
        return 0;
    }

    if(n<=6)
    {
        int r1=oo,r2=0;
        for(int i=0;i<(1<<n);i++)
        {
            vector<int> nodes;
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                    nodes.push_back(j);
            if(nodes.size()>r1)
                continue;
            if(is_ok(nodes))
            {
                if(nodes.size()<r1)
                {
                    r1=nodes.size();
                    r2=1;
                }
                else
                    r2++;
            }
        }
        if(r1==oo)
            db(-1)
        else
        {
            for(int i=1;i<=r1;i++)
                r2*=i;
            cout << r1 << ' ' << r2 << '\n';
        }
        return 0;
    }

    cout << 1 << ' ';
    int cant=0;
    for(int i=0;i<n;i++)
        cant+=is_ok({i});
    cout << cant << '\n';

    return 0;
}