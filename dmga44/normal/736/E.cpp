#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<vector<int>> solve(vector<pii> v)
{
    int n=v.size();
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v.size()-1;j++)
        {
            if(j<v.back().f)
            {
                ans[v.back().s][v[j].s]=1;
            }
            else
            {
                ans[v[j].s][v.back().s]=1;
                v[j].f--;
            }
        }
        v.pop_back();
        sort(all(v));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    if(sum>n*(n-1))
    {
        db("no")
        return 0;
    }
    int fal=n*(n-1)-sum;
    int r=0;
    if(n-m)
        r=fal%(n-m);

    for(int i=m;i<n;i++)
    {
        a[i]=fal/(n-m);
        if(r>(i-m))
            a[i]++;
    }

    reverse(all(a));

    sum=a[0];
    bool ok=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
            ok=0;
        sum+=a[i];
        if(sum<i*(i+1))
            ok=0;
    }
    if(!ok)
    {
        db("no")
        return 0;
    }

    vector<int> a1(n),a2(n);
    vector<pii> p1,p2;
    sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum&1)
        {
            a1[i]=(a[i]+1)/2;
            a2[i]=a[i]-a1[i];
        }
        else
        {
            a1[i]=a[i]/2;
            a2[i]=a[i]-a1[i];
        }
        p1.push_back(pii(a1[i],i));
        p2.push_back(pii(a2[i],i));
        sum+=a[i];
    }

    sort(all(p1));
    sort(all(p2));

    vector<vector<int>> k1=solve(p1);
    vector<vector<int>> k2=solve(p2);

    vector<vector<int>> ans=k1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j]+=k2[i][j];

    db("yes")
    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout << 'X';
            else
                cout << "LDW"[ans[i][j]];
        }

    return 0;
}
/**
3 3
3 3 1
**/