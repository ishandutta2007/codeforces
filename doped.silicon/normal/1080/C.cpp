#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second





#define PI 3.1415926535897932385
#define INF 1000000000000000
#define EPS 1e-7
// #define MAXN 100000
#define MOD 1000000007
#define dec decr
// ll ans[10000000];
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll ww(ll x, ll y)
{
    ll l1=x%2+x/2;
    ll l3=y%2+y/2;
    ll l2=x/2;
    ll l4=y/2;
    return l1*l3+l2*l4;
}
ll wi(ll x,ll y,ll x1,ll y1)
{
    return ww(x1,y1)-ww(x,y1)-ww(x1,y)+ww(x,y);
}
ll bi(ll x,ll y,ll x1,ll y1,ll n,ll m)
{
    return n*m-(ww(x1,y1)-ww(x,y1)-ww(x1,y)+ww(x,y));
}
int main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(2);
        cout<<fixed;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
        {
            ll n,m;
            cin>>n>>m;
            swap(n,m);
            ll a,b,c,d;
            ll w,x,y,z;
            cin>>a>>b>>c>>d;

            cin>>x>>y>>w>>z;
            ll x1=max(a,x);
            ll x2=min(c,w);
            ll y1=max(b,y);
            ll y2=min(d,z);
            x1--;
            y1--;
            x--;
            y--;
            a--;
            b--;
            // debug(x1);
            // debug(y1);
            // debug(x2);
            // debug(y2);

            if(x1<x2&&y1<y2)
            {
                ll xx=bi(a,b,c,d,c-a,d-b)-bi(x1,y1,x2,y2,x2-x1,y2-y1);
                ll yy=wi(x,y,w,z);
                ll zz=ww(n,m);
                // debug(xx);
                // debug(yy);
                // debug(zz);
                ll bb=n*m-zz;
                cout<<zz+xx-yy<<" "<<bb+yy-xx<<endl;
            }
            else
            {
                ll xx=bi(a,b,c,d,c-a,d-b);
                ll yy=wi(x,y,w,z);
                ll zz=ww(n,m);
                ll bb=n*m-zz;
                cout<<zz+xx-yy<<" "<<bb+yy-xx<<endl;
            }
        }

            return 0;
}