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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN 100005

bool solve(vector<pii> &a,int cant,int tar)
{
    vector<int> mk(a.size()*2);
    for(int i=0;i<cant;i++)
    {
//        cout << a[i].s << '\n';
        mk[a[i].s]=1;
    }
    for(int i=1;i<mk.size();i++)
        if(mk[i] && mk[i-1])
            mk[i]=0;
    int c=0;
    for(auto y : mk)
        c+=y;
//    cout << c << ' ' << cant << '\n';
    return c>=tar;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    int imp=(k+1)/2;
    int pp=k/2;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<pii> avi,avp;
    for(int i=0;i<n;i++)
    {
        avi.push_back(pii(a[i],i));
        avp.push_back(pii(a[i],i));
        if(!i)
            avp.pop_back();
        if(i==n-1)
        {
            if(imp>pp)
                avp.pop_back();
            else
                avi.pop_back();
        }
    }

    sort(all(avi));
    sort(all(avp));

//        db("xxx")
    int p1=-1,p2=-1;
    for(int i=(1<<18);i;i>>=1)
        if(p1+i<avi.size() && !solve(avi,p1+i,imp))
            p1+=i;
    for(int i=(1<<18);i;i>>=1)
        if(p2+i<avp.size() && !solve(avp,p2+i,pp))
            p2+=i;
//    p1++,p2++;
//        db(p1)
//        db(p2)
//    db(avi.size())
//    db(avp.size())
    db(min(avi[p1].first,avp[p2].first))

    return 0;
}