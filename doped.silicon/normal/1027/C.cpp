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
            ll t;
            cin>>t;
            rep(jdfa,t)
            {
                ll n;
                cin>>n;
                ll a[n+1];
                bool awe=true;

                rep(i,n)
                {
                    cin>>a[i];
                }
                a[n]=-4;
                sort(a,a+n);
                vector<ll>v;
                //
                //cout<<"fjbdhs"<<endl;
                for(ll i=n-1;i>=1;i--)
                {
                    if(i>=3&&a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i-2]==a[i-3])
                    {
                        cout<<a[i]<<" "<<a[i]<<" "<<a[i]<<" "<<a[i]<<endl;
                        awe=0;
                        break;
                    }
                    else if(a[i]==a[i-1]&&a[i]!=a[i+1])
                    {
                        v.pb(a[i]);
                    }
                    //cout<<"fjbdhs"<<endl;
                }
                if(awe)
                {
                    ll dif=1004908409850924;
                    double ans=dif;
                    ll a1=0,b1=0;
                    rep(i,v.size()-1)
                    {
                        dif=min(dif,abs(v[i]-v[i+1]));
                        if(pow(v[i]+v[i+1],2)/(v[i]*v[i+1])<ans)
                        {
                            ans=pow(v[i]+v[i+1],2)/(v[i]*v[i+1]);
                            a1=v[i];
                            b1=v[i+1];
                        }
                    }
                    
                            cout<<a1<<" "<<a1<<" "<<b1<<" "<<b1<<endl;
                            //break;
                }
            }
            return 0;
}