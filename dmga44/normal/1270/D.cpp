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
#define MAXN (ll)(1e3+5)

pii ask(int pos,int k)
{
    bool kk[k];
    for(int i=0;i<k;i++)
        kk[i]=1;
    if(pos!=-1)
        kk[pos]=0;
    cout << "?";
    for(int i=0;i<k;i++)
        if(kk[i])
            cout << ' ' << i+1;
    if(pos!=-1)
        cout << ' ' << k+1;
    cout << '\n';
    cout.flush();
    int p,v;
    cin >> p >> v;
    return pii(p,v);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,k;
    cin >> n >> k;
    pii base=ask(-1,k);
    base.f--;
    vector<pii> rr(k);
    for(int i=0;i<k;i++)
    {
        rr[i]=ask(i,k);
        rr[i].f--;
    }
    int res=0;
    if(base.s>rr[base.f].s) ///menor
    {
        for(int i=0;i<k;i++)
            if(i!=base.f && rr[i].s>rr[base.f].s)
                res++;
        res++;
    }
    else ///mayor
    {
        for(int i=0;i<k;i++)
            if(rr[i].s>base.s)
                res++;
    }
    cout << "! " << res<< '\n';
    cout.flush();
    return 0;
}