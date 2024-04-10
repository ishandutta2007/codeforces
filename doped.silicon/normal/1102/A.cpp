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

ll sum=0;
ll lcm(ll a,ll b)
{
    if(a==0&&b==0)
        return 1;
    if(a==0)
        return b;
    else if(b==0)
        return a;
    ll j= (a*b/gcd(a,b));
    if(a/gcd(a,b)>INF/b)
        return INF;
    else
        return j;

}
ll mark[100007];
vector<ll>g[100007];

ll dfs(ll n)
{
    mark[n]=1;
    if(n!=1&&g[n].size()==1)// basecondition
    {
        return 1;
    }
    rep(i,g[n].size())
    {
        if(mark[g[n][i]]==0)
        {
            
        }
    }
    return 1;//return what you want
}
            ll dist[200+1][200+1];
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
            ll a=0;ll b=0;
            if(n%4==0||n%4==3)
                cout<<"0";
            else
                cout<<"1";
            return 0;
}