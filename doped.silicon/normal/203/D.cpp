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
#define INF 1000000000000000000
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

ll ar[8001];
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll x,z,y;
            ll vx,vy,vz;
            cin>>x>>z>>y;
            cin>>vx>>vy>>vz;
            vy*=-1;
            double t=1.0*y/vy;
            double fx,fz;
            ll d=(ll)(vz*t/z);
            if(d%2==0)
            {
                fz=vz*t-z*d;
            }
            else
            {
                fz=z-(vz*t-z*d);
            }
            if(vx>0)
            {
                 d=(ll)(vx*t/(2*x));
                if(vx*t-d*x*2>1.5*x)
                {
                    fx=vx*t-d*x*2-1.5*x;
                } 
                else if((vx*t-d*x*2<0.5*x))
                {
                    fx=vx*t-d*x*2+0.5*x;   
                }
                else
                {
                    fx=1.5*x-vx*t+d*x*2;
                }
                
            }
            else
            {
                d=abs(vx*t/(2*x));
                vx*=-1;
                if(vx*t-d*x*2>1.5*x)
                {
                    fx=vx*t-d*x*2-1.5*x;
                    fx=x-fx;
                } 
                else if((vx*t-d*x*2<0.5*x))
                {
                    fx=vx*t-d*x*2+0.5*x;  
                    fx=x-fx; 
                }
                else
                {
                    fx=1.5*x-vx*t+d*x*2;
                    fx=x-fx;
                }
            }
            cout<<setprecision(10)<<fx<<" "<<fz;
            return 0;
}