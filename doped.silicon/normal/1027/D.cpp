
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

ll mark[300000];
ll c[300000];
ll nex[300000];
ll mi=133465456313;ll ma=10000000;ll ans=0;
ll findmin(ll n)
{
	//debug(n);
	//debug(mark[n]);
	if(mark[n]==-2)
	{
	//	cout<<"out f here"<<endl;
		
		return mi;
	}
	else
	{
		mark[n]--;
		mi=min(mi,c[n]);
		return findmin(nex[n]);
		
	}
	return mi;
}
void search(ll n)
{
   // debug(n);
    if(mark[n]==ma)
    {
    	// debug(mark[n]);
    	// debug(ma);
    	mark[n]=-1;
    // debug(n);
    mi=32443545321321;
    	mi=findmin( n);
         ans+=mi;
         ma+=1000000000;
         
    }
    else if(mark[n]==0)
    {
        mark[n]=ma;
       // mi=min(mi,c[n]);
        search(nex[n]);
    }
   // debug(ans);
}
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n;
            cin>>n;
            //debug(n);
            rep(i,n)
            {
                cin>>c[i];
            }
            rep(i,n)
            {
                cin>>nex[i];
                nex[i]--;
            }
            
            rep(i,n)
            {
            	
                search(i);
                //debug(i);
                ma+=1000000000;
            }
            cout<<ans<<endl;
            return 0;
}