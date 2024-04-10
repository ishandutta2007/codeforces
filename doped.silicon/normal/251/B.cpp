#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define debug(x) cout<<#x<<": "<<x<<endl
#define dbug(x,y) cout<<x<<" "<<y<<endl

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
//END OF COMPETITVE PROGRAMMING TEMPLATE
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,k;
        cin>>n>>k;
        ll q[n],m[n],a[n],b[n]={0},c[n];
        rep(i,n)
        {
            cin>>q[i];
        }
        rep(i,n)
        {
            a[i]=i+1;
            b[i]=i+1;
            cin>>m[i];
        }
        ll p=1;
        rep(i,n)
        {
            if(m[i]!=i+1)
                p=0;
        }
        if(p)
        {
            cout<<"NO";
            return 0;
        }
        rep(i,n)
        {
            b[i]=a[q[i]-1];
        }
        rep(i,n)
        {
            c[q[i]-1]=a[i];
        }
        ll zz=1;
        rep(i,n)
        {
            if(b[i]!=c[i]||b[i]!=m[i])
                zz=0;
        }
        if(zz)
        {
            if(k==1)
                cout<<"YES";
            else
                cout<<"NO";
            return 0;
        }
        rep(j,k)
        {
            rep(i,n)
            {
                b[i]=a[q[i]-1];
            }
            ll z=1;
            rep(i,n)
            {
                a[i]=b[i];
                if(b[i]!=m[i])
                    z=0;
            }
            if(z&&(k-j-1)%2==0)
            {
               // debug(j);
                cout<<"YES";
                return 0;
            }
        }
        rep(i,n)
        {
            a[i]=i+1;
            b[i]=i+1;
        }
        rep(j,k)
        {
            rep(i,n)
            {
                b[q[i]-1]=a[i];
            }
            ll z=1;
            rep(i,n)
            {
                // debug(b[i]);
                a[i]=b[i];
                if(b[i]!=m[i])
                {
                    z=0;
                }
            }
            if(z&&(k-j-1)%2==0)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
        return 0;
}