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
ll dp[37][37];
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            if(abs(c-d)>1)
            {
                cout<<"-1"<<endl;
                return 0;
            }           
            if(c>d)
            {
                if(a<c||b<c)
                {
                cout<<"-1"<<endl;
                return 0;
                }
                ll ex1=a-c;
                ll ex2=b-c;
                rep(i,ex1)
                {
                    cout<<"4";
                }
                rep(i,c)
                {
                    cout<<"47";
                }
                rep(i,ex2)
                    cout<<"7";
            }
            else if(c<d)
            {
                if(a<d||b<d)
                {
                cout<<"-1"<<endl;
                return 0;
                }
                ll ex1=a-d;
                ll ex2=b-d;
                cout<<"74";
                rep(i,ex1)
                    cout<<"4";
                rep(i,d-2)
                {
                    cout<<"74";
                }
                rep(i,ex2)
                {
                    cout<<"7";
                }
                cout<<"74";
            }
            else
            {
                if(a<c+1&&b<c+1)
                {
                cout<<"-1"<<endl;
                return 0;
                }
                if(a>=c+1)
                {
                    ll ex1=a-c-1;
                    ll ex2=b-c;
                    if(ex1<0||ex2<0)
                    {
                        cout<<"-1";
                        return 0;
                    }
                    rep(i,ex1+1)
                    {
                        cout<<"4";
                    }
                    rep(i,c-1)
                    {
                        cout<<"74";
                    }
                    rep(i,ex2+1)
                    {
                        cout<<"7";
                    }
                    cout<<"4";
                    
                }
                else
                {
                    ll ex1=a-c;
                    ll ex2=b-c;
                    if(ex1<0||ex2<0)
                    {
                        cout<<"-1";
                        return 0;
                    }
                    cout<<"74";
                    rep(i,ex1)
                    {
                        cout<<"4";
                    }
                    rep(i,c-1)
                    {
                        cout<<"74";
                    }
                    rep(i,ex2)
                    {
                        cout<<"7";
                    }
                }
            }
            return 0;
}