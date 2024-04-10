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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (ll)(2e5+5)
#define mod (ll)(998244353)

int b[MAXN],a[MAXN];
int acmi[MAXN],acm[MAXN];
int p1[MAXN],p2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int j=0;j<m;j++)
        cin >> b[j];

    acm[0]=a[0];
    for(int i=1;i<n;i++)
        acm[i]=min(acm[i-1],a[i]);

    acmi[n]=1e9;
    for(int i=n-1;i>=0;i--)
        acmi[i]=min(acmi[i+1],a[i]);

    int pos=0;
    bool ok=1;
    for(int i=0;i<m-1 && ok;i++)
    {
        ok&=(acmi[pos]==b[i]);
        p1[i]=pos;
        while(pos<n-1 && acmi[pos]!=b[i+1])
            pos++;
    }
    p1[m-1]=pos;
    ok&=(acmi[pos]==b[m-1]);

//    db(pos)
//    db(ok)
    pos=n-1;
    for(int i=m-1;i>0 && ok;i--)
    {
        while(pos && acmi[pos]!=b[i])
            pos--;
        p2[i]=pos;
        ok&=(acmi[pos]==b[i]);
    }
//    cout << pos << '\n';
    pos=0;
    p2[0]=pos;
    ok&=(acmi[pos]==b[0]);

//    for(int i=0;i<m;i++)
//        cout << p1[i] << ' ';
//    cout << '\n';
//    for(int i=0;i<m;i++)
//        cout << p2[i] << ' ';
//    cout << '\n';

    ll res=1;
    for(int i=1;i<m;i++)
        res=(res*(p2[i]-p1[i]+1))%mod;
    res=(res*(int)(ok));
    db(res)

    return 0;
}
/**
6 3
12 10 20 20 25 30
10 20 30

8 2
1 2 2 2 2 2 2 2
1 2

4 1
1 1 1 2
1
**/