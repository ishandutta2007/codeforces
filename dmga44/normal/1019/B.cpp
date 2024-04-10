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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int n;

pii ask(int p)
{
    cout << "? " << p+1 << '\n';
    cout.flush();
    int x;
    cin >> x;
    cout << "? " << (p+(n/2))%n+1 << '\n';
    cout.flush();
    int y;
    cin >> y;
    return pii(x,y);
}

void ans(int p)
{
    cout << "! " << p+1 << '\n';
    cout.flush();
    exit(0);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n;
    if(n%4)
    {
        cout << "! -1\n";
        cout.flush();
        return 0;
    }

    pii p1=ask(0);
    if(p1.f==p1.s)
        ans(0);
    pii p2=ask(n/4);
    if(p2.f==p2.s)
        ans(n/4);
    int a[4];
    a[0]=p1.f;
    a[2]=p1.s;
    a[1]=p2.f;
    a[3]=p2.s;

    int p=-1;
    for(int i=0;i<4;i++)
        if(a[i]<a[(i+2)%4] && a[(i+1)%4]>a[(i+3)%4])
            p=i;
    ll pos=0;
    for(int po=(1<<15);po;po>>=1)
    {
        if(pos+po>=n/4)
            continue;
        int act=p*n/4+pos+po;
        pii x=ask(act);
        if(x.f==x.s)
            ans(act);
        if(x.f<x.s)
            pos+=po;
    }
    return 0;
}