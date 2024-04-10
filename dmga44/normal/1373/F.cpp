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
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int solve(int ini,vector<int> &a,vector<int> &b)
{
    int n=a.size();
    vector<int> sumb(n);
    sumb[n-1]=ini;
    if(b[0]>=a[0]-ini)
        sumb[0]=a[0]-ini;
    else
        return -1;
//    db("")
//    for(auto y : sumb)
//        cout << y << ' ';
//    cout << '\n';
    for(int i=1;i<n-1;i++)
    {
        int fal0=b[i-1]-sumb[i-1];
        int f1=b[i];
        sumb[i-1]+=min(fal0,a[i]);
        if(a[i]-min(fal0,a[i])<=f1)
            sumb[i]+=a[i]-min(fal0,a[i]);
        else
            return -1;
//        for(auto y : sumb)
//            cout << y << ' ';
//        cout << '\n';
    }
    int i=n-1;
    int fal0=b[i-1]-sumb[i-1];
    int f1=b[i]-sumb[n-1];
    sumb[i-1]+=min(fal0,a[i]);
    if(a[i]-min(fal0,a[i])<=f1)
        sumb[i]+=a[i]-min(fal0,a[i]);
    else
        return 1;
//    for(auto y : sumb)
//        cout << y << ' ';
//    cout << '\n';
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];
        int ok=0;
        bool flag=0;
        for(int po=(1<<29);po;po>>=1)
        {
            if(ok+po>min(a[0],b[n-1]))
                continue;
            int x=solve(ok+po,a,b);
//            cout << ok+po << ' ' << x << '\n';
            if(!x)
            {
                flag=1;
                break;
            }
            if(x==-1)
                ok+=po;
        }

        if(flag || !solve(ok,a,b))
            db("YES")
        else
            db("NO")
    }

    return 0;
}
/**
1
4
2 3 4 5
3 7 2 2
**/