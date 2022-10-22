#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> ans;

vector<int> xor_basis(vector<int> v1,vector<int> v2)
{
    // for(auto y : v2)
    //     v1.push_back(y);
    for(int i=0;i<v1.size();i++)
        for(int j=0;j<v2.size();j++)
            if((v1[i]^v2[j])<v1[i])
                v1[i]^=v2[j];
    int p=0;
    for(int i=19;i>=0;i--)
    {
        if(p==v1.size())
            continue;
        int piv=-1;
        for(int j=p;j<v1.size();j++)
            if(v1[j]&(1<<i))
                piv=j;
        if(piv==-1)
            continue;
        swap(v1[p],v1[piv]);
        for(int j=p+1;j<v1.size();j++)
        {
            if(v1[j]&(1<<i))
                v1[j]^=v1[p];
        }
        p++;
    }
    for(auto y : v1)
        v2.push_back(y);
    sort(allr(v2));
    while(!v2.empty() && v2.back()==0)
        v2.pop_back();
    return v2;
}

void solve(int l,int r,vector<pip>& qs,vector<int>& a)
{
    if(l==r)
    {  
        for(auto y : qs)
            ans[y.first]=a[l];
        return;
    }
    int mid=(l+r)>>1;

    vector<pip> qsl,qsr;
    vector<pip> act;
    for(auto q : qs)
    {
        if(q.second.first>mid)
            qsr.push_back(q);
        else if(q.second.second<=mid)
            qsl.push_back(q);
        else
            act.push_back(q);
    }

    solve(l,mid,qsl,a);
    solve(mid+1,r,qsr,a);
    // cerr << l << ' ' << r << '\n';

    vector<pii> xbl,xbr;
    vector<int> actl,actr;
    xbl.push_back({mid,a[mid]});
    xbr.push_back({mid,a[mid]});
    actl.push_back(a[mid]);
    actr.push_back(a[mid]);
    // cout << l << ' ' << r << '\n';
    for(int i=mid-1;i>=l;i--)
    {
        int x=a[i];
        for(auto y : actl)
            if((x^y)<x)
                x^=y;
        
        if(x)
        {
            actl.push_back(x);
            sort(allr(actl));
            xbl.push_back(pii(i,x));
        }
    }
    // db(mid)

    for(int i=mid+1;i<=r;i++)
    {
        int x=a[i];
        for(auto y : actr)
            if((x^y)<x)
                x^=y;
        
        if(x)
        {
            actr.push_back(x);
            sort(allr(actr));
            xbr.push_back(pii(i,x));
        }
    }
    // db(mid)
    
    for(auto q : act)
    {
        int id=q.first;
        // cout << "\n\n";
        // cout << l << ' ' << r << ' ' << id << '\n';
        int l=q.second.first;
        int r=q.second.second;
        // cout << l << ' ' << r << ' ' << id << '\n';
        vector<int> xl,xr;
        for(auto y : xbl)
            if(y.first>=l)
                xl.push_back(y.second);
        for(auto y : xbr)
            if(y.first<=r)
                xr.push_back(y.second);
        // for(auto y : xl)
        //     cout << y << ' ';
        // cout << '\n';
        // for(auto y : xr)
        //     cout << y << ' ';
        // cout << '\n';
        vector<int> base=xor_basis(xl,xr);
        int v=0;
        for(auto y : base)
            if((v^y)>v)
                v^=y;
        ans[id]=v;
    }
    // db("xxx")
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    int q;
    cin >> q;
    ans.resize(q);
    vector<pip> qs;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        qs.push_back(pip(i,pii(l,r)));
    }

    solve(0,n-1,qs,a);

    for(auto y : ans)
        cout << y << '\n';

    return 0;   
}