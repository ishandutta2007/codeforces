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

int a[MAXN],b[MAXN];
int mm[MAXN];

int solve(vector<int> &mark,int k)
{
//    for(auto y : mark)
//        cout << y << ' ';
//    cout << '\n';
    int sz=mark.size();
    int ma=sz/k;
    int res=0,last=-1,cant=0;
    for(int i=0;i<sz;i++)
        if(mark[i])
        {
            cant++;
            if(i<=last)
                continue;
            res++;
            last=i+k-1;
        }
    if(res && !ma)
        res=-1;
    else if(res)
        res=1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    ll x,k,y;
    cin >> x >> k >> y;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mm[a[i]]=i;
    }

    vector<int> pos;
    bool ok=1;
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        pos.push_back(mm[b[i]]);
        if(i && pos[i]<pos[i-1])
            ok=0;
    }

    if(!ok)
    {
        db(-1)
        return 0;
    }

//    db("xxx")
    int last=-1;
    ll res=0;
    pos.push_back(n);
    for(int i=0;i<m+1;i++)
    {
        if(last+1==pos[i])
        {
            last++;
            continue;
        }
        vector<int> mark;
        int ma=a[pos[i]];
        if(last!=-1)
            ma=max(ma,a[last]);

        for(int j=last+1;j<pos[i];j++)
            mark.push_back(a[j]>ma);

        ll mi=solve(mark,k);

        if(mi==-1)
        {
            ok=0;
            break;
        }
        else
        {
            res+=mi*x;
            res+=(min(x,k*y)*((mark.size()/k)-mi));
            res+=y*(mark.size()%k);
        }

        last=pos[i];
    }
    if(!ok)
        db(-1)
    else
        db(res)

    return 0;
}
/**
5 2
5 2 3
3 1 4 5 2
3 5

4 2
1 2 3
1 3 4 2
1 2
**/