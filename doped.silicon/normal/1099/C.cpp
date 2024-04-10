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
        ll k;
        string s;
        cin>>s>>k;
        ll st=0,c=0;
        ll n=s.length();
        rep(i,n)
        {
            if(s[i]=='*')
            {
                st++;
            }
            else if(s[i]=='?')
                c++;
        }
        // debug(st);
        ll mi=n-2*(st+c);
        ll ma=mi+(st+c);
        // debug(c);
        // debug(ma);
        // debug(mi);
        ll z=ma;
        if(st!=0)
        {
            ma=INF;
        }
        // debug(ma);
        if(k<mi||k>ma)
        {
            cout<<"Impossible";
        }
        else
        {
            if(k>=z)
            {
                ll e=k-z;
                ll f=1;
                rep(i,n)
                {
                    if(s[i]=='*'&&f)
                    {
                        rep(j,e)
                        {
                            cout<<s[i-1];
                        }
                        f=0;
                    }
                    else
                    {
                        if(s[i]!='*'&&s[i]!='?')
                        {
                            cout<<s[i];
                        }
                    }
                }
            }
            else
            {
                ll d=z-k;
                rep(i,n)
                {
                    if((i+1)<n&&(s[i+1]=='*'||s[i+1]=='?')&&d>0)
                    {
                        d--;
                    }
                    else
                    {
                        if(s[i]!='*'&&s[i]!='?')
                        {
                            cout<<s[i];
                        }
                    }
                }
            }
        }




            return 0;
}