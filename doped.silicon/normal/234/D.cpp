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
ll fav[200];
ll ar[200][2];
int main () 
{
  ios_base::sync_with_stdio(false);
            cin.tie(NULL);
     
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        
            ll m,k;
            cin>>m>>k;
            rep(i,k)
            {
                ll x;
                cin>>x;
                fav[x]=1;
            }
            ll n;
            cin>>n;
            ll xx=0,vv=0;
            rep(i,n)
            {
                string s;
                cin>>s;
                // debug(s);
                ll x;
                cin>>x;
                ll z=0,f=0;
                rep(i,x)
                {
                    ll p;
                    cin>>p;
                    if(p==0)
                        z++;
                    else
                    {
                        if(fav[p]==1)
                        {
                            f++;
                        }
                    }
                }
                if(z>0)
                {
                    xx++;
                    vv=i;
                }
                ar[i][1]=min(k,z+f);
                //debug(ar[i][1]);
                ll uf=x-z-f;
                uf=m-k-uf;
                if(z>uf)
                {
                    f+=z-uf;
                }
                ar[i][0]=f;
            }
            ll ma=0;
            ll ma1=0;
            ll mi=0;
            rep(i,n)
            {
                //ma=max(ma,ar[i][1]);
                if(ar[i][1]>ma)
                {
                    ma1=ma;
                    ma=max(ma,ar[i][1]);
                }
                else if(ar[i][1]>ma1)
                {
                    ma1=ar[i][1];
                }
                mi=max(mi,ar[i][0]);
            }
            ll ans[n];
            ll zz=0;
            ll kk=0;
            rep(i,n)
            {
                if(ar[i][0]==ma)
                {
                    ans[i]=0;
                    zz++;
                }
                else if(ar[i][1]<mi)
                {
                    ans[i]=1;
                    kk++;
                }
                else
                {
                    ans[i]=2;
                }
            }
            if(kk==n-1)
            {
                rep(i,n)
                {
                if(ans[i]!=1)
                    ans[i]=0;
                }
            }
            else if(zz==0)
            {
                // debug(ar[4][1]);
                // debug(ma1);
                // debug(ar[4][0]);
                rep(i,n)
                {
                    if(ma==ar[i][1]&&ma1==ar[i][0])
                    {
                        ans[i]=0;

                    }
                }
            }
            rep(i,n)
            {
                cout<<ans[i]<<endl;
            }
            return 0;
}