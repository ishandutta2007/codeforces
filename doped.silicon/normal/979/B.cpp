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
            ll n;
            cin>>n;
            string a,b,c;
            cin>>a>>b>>c;
            ll a1[52]={0};
            ll b1[52]={0};
            ll c1[52]={0};
            
            rep(i,a.length())
            {
                if(a[i]<='Z')
                    a1[26+(a[i]-'A')]++;
                else
                    a1[a[i]-'a']++;
            }
            rep(i,b.length())
            {
                if(b[i]<='Z')
                    b1[26+(b[i]-'A')]++;
                else
                b1[b[i]-'a']++;
            }
            rep(i,c.length())
            {
                if(c[i]<='Z')
                    c1[26+(c[i]-'A')]++;
                else
                c1[c[i]-'a']++;
            }
            ll a2=0,b2=0,c2=0;
            rep(i,52)
            {
                a2=max(a2,a1[i]);
                b2=max(b2,b1[i]);
                c2=max(c2,c1[i]);
            }
            // debug(a2);
            // dbug(b2,c2);
            ll a3=min((ll)a.length(),(ll)(a2+n));
            ll b3=min((ll)b.length(),(ll)(b2+n));
            ll c3=min((ll)c.length(),(ll)(c2+n));
            
            if(n==1)
            {
                if(a2==a.length())
                    a3--;
                if(b2==b.length())
                    b3--;
                if(c2==c.length())
                    c3--;
            }
            ll ma=max(a3,max(b3,c3));

            if((ma==a3&&ma==b3)||(ma==a3&&ma==c3)||(ma==c3&&ma==b3))
            {
                cout<<"Draw";
            }
            else if(ma==a3)
            {
                cout<<"Kuro";
            }
            else if(ma==b3)
            {
                cout<<"Shiro";
            }
            else if(ma==c3)
            {
                cout<<"Katie";
            }
        return 0;
}