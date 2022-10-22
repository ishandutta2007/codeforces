#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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
#define MAXN (ll)(4e5+5)

pii operator+(pii a,pii b)
{
    return pii(a.first+b.first,a.second+b.second);
}

pii operator-(pii a,pii b)
{
    return pii(a.first-b.first,a.second-b.second);
}

vector<int> tt[MAXN][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m;
    cin >> n >> m >> k;
    vector<int> t(n);
    vector<int> ts[4];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> t[i];
        cin >> a >> b;
        ts[a*2+b].push_back(t[i]);
        tt[t[i]][2*a+b].push_back(i);
    }

    for(int i=0;i<4;i++)
        sort(all(ts[i]));

    if(ts[3].size()+ts[1].size()<k || ts[3].size()+ts[2].size()<k)
    {
        db(-1)
        return 0;
    }

    vector<int> acs[4];
    for(int i=0;i<4;i++)
    {
        acs[i].push_back(0);
        for(auto y : ts[i])
            acs[i].push_back(acs[i].back()+y);
    }

    pii res=pii(2e9+5,0);
    for(int i=0;i<=m;i++)
    {
        if(acs[3].size()>i && acs[1].size()>max(k-i,0) && acs[2].size()>max(k-i,0) && m<=i+ts[1].size()+ts[2].size()+ts[0].size() && m>=i+2*max(k-i,0))
        {
            int s1=acs[3][i]+acs[1][max(k-i,0)]+acs[2][max(k-i,0)];
            int ant=2*max(k-i,0);
            int faltan=m-(i+ant);

            int ma=0;
            for(int po=(1<<13);po;po>>=1)
            {
                if(ma+po>=1e4)
                    continue;
                pii x=pii(0,0);
                int p2=lower_bound(all(ts[0]),ma+po+1)-ts[0].begin();
                x=x+pii(acs[0][p2],p2);
                p2=lower_bound(all(ts[1]),ma+po+1)-ts[1].begin();
                if(p2>max(k-i,0))
                    x=x+pii(acs[1][p2]-acs[1][max(k-i,0)],p2-max(k-i,0));
                p2=lower_bound(all(ts[2]),ma+po+1)-ts[2].begin();
                if(p2>max(k-i,0))
                    x=x+pii(acs[2][p2]-acs[2][max(k-i,0)],p2-max(k-i,0));
                if(x.second<faltan)
                    ma+=po;
            }
            ma++;

            pii x=pii(0,0);
            int po=0;
            int p2=lower_bound(all(ts[0]),ma+po+1)-ts[0].begin();
            x=x+pii(acs[0][p2],p2);
            p2=lower_bound(all(ts[1]),ma+po+1)-ts[1].begin();
            if(p2>max(k-i,0))
                x=x+pii(acs[1][p2]-acs[1][max(k-i,0)],p2-max(k-i,0));
            p2=lower_bound(all(ts[2]),ma+po+1)-ts[2].begin();
            if(p2>max(k-i,0))
                x=x+pii(acs[2][p2]-acs[2][max(k-i,0)],p2-max(k-i,0));

            s1+=x.first-(x.second-faltan)*ma;
            res=min(res,pii(s1,i));
        }
    }
    if(res.first==2e9+5)
    {
        db(-1)
        return 0;
    }

    db(res.first)
    int cant=res.second;
    for(int i=0;i<cant;i++)
    {
        cout << tt[ts[3][i]][3].back()+1 << ' ';
        tt[ts[3][i]][3].pop_back();
    }

    for(int i=0;i<max(k-cant,0);i++)
    {
        cout << tt[ts[2][i]][2].back()+1 << ' ';
        tt[ts[2][i]][2].pop_back();
    }

    for(int i=0;i<max(k-cant,0);i++)
    {
        cout << tt[ts[1][i]][1].back()+1 << ' ';
        tt[ts[1][i]][1].pop_back();
    }

    int faltan=m-cant-2*max(k-cant,0);
    vector<pii> lt;
    for(int i=max(k-cant,0);i<ts[2].size();i++)
        lt.push_back(pii(ts[2][i],2));
    for(int i=max(k-cant,0);i<ts[1].size();i++)
        lt.push_back(pii(ts[1][i],1));
    for(int i=0;i<ts[0].size();i++)
        lt.push_back(pii(ts[0][i],0));

    sort(all(lt));

    for(int i=0;i<faltan;i++)
    {
        int v=lt[i].first;
        int t=lt[i].second;
        cout << tt[v][t].back()+1 << ' ';
        tt[v][t].pop_back();
    }
    cout << '\n';

    return 0;
}
/**
6 3 1
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1

6 3 2
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1
**/