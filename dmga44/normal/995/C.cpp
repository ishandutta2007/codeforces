#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int clasify(point a)
{
    if(a.real()>=0 && a.imag()>0)
        return 0;
    if(a.real()<0 && a.imag()>=0)
        return 1;
    if(a.real()<=0 && a.imag()<0)
        return 2;
    return 3;
}

vector<int> dir[4];
point arr[2*MAXN];
vector<pii> g[MAXN];
int cont;
int cantt[MAXN];
bool mk[MAXN];

bool ok1()
{
    return dir[0].size()>1 || dir[1].size()>1 || dir[2].size()>1 || dir[3].size()>1;
}

void mix(int i)
{
    int u=dir[i].back();
    dir[i].pop_back();
    int v=dir[i].back();
    dir[i].pop_back();

    point a=arr[u];
    point b=arr[v];

    g[cont].push_back(pii(u,0));
    g[cont].push_back(pii(v,1));

    arr[cont]=a-b;
    dir[clasify(arr[cont])].push_back(cont);
    cont++;
}

bool ok2()
{
    return (dir[0].size() && dir[2].size()) || (dir[1].size() && dir[3].size());
}

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
    {
        int v=y.f;
        int w=y.s;
        if(!mk[v])
        {
            if(w)
                cantt[v]=1-cantt[u];
            else
                cantt[v]=cantt[u];
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cont=n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        arr[i]=point(x,y);
        dir[clasify(point(x,y))].push_back(i);
    }

    while(ok2() || ok1())
    {
        if(dir[0].size() && dir[2].size())
        {
            int u=dir[0].back();
            dir[0].pop_back();
            int v=dir[2].back();
            dir[2].pop_back();

            point a=arr[u];
            point b=arr[v];

            g[cont].push_back(pii(u,0));
            g[cont].push_back(pii(v,0));

            arr[cont]=a+b;
            dir[clasify(arr[cont])].push_back(cont);
            cont++;
        }
        if(dir[1].size() && dir[3].size())
        {
            int u=dir[1].back();
            dir[1].pop_back();
            int v=dir[3].back();
            dir[3].pop_back();

            point a=arr[u];
            point b=arr[v];

            g[cont].push_back(pii(u,0));
            g[cont].push_back(pii(v,0));

            arr[cont]=a+b;
            dir[clasify(arr[cont])].push_back(cont);
            cont++;
        }
        for(int i=0;i<4;i++)
            if(dir[i].size()>1)
                mix(i);
    }

    int u=-1;
    if(dir[0].size())
        u=dir[0].back();
    if(dir[2].size())
        u=dir[2].back();
    int v=-1;
    if(dir[1].size())
        v=dir[1].back();
    if(dir[3].size())
        v=dir[3].back();
    if(u!=-1 && v!=-1)
    {
        point a=arr[u];
        point b=arr[v];
        arr[cont]=a+b;
        g[cont].push_back(pii(u,0));
        g[cont].push_back(pii(v,(abs(arr[cont])>1.45e6)));

        dir[clasify(arr[cont])].push_back(cont);
        cont++;
    }

    cont--;
    dfs(cont);

    for(int i=0;i<n;i++)
    {
        if(cantt[i])
            cout << '-';
        cout << 1 << ' ';
    }
    cout << '\n';
    return 0;
}
/**
3
99999 0
0 99999
99999 0
2
-1 -1
1 1
1
0 0
2
1 1
1 1
**/