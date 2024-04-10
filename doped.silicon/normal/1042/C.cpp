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
        cout<<setprecision(2);
        cout<<fixed;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;
        cin>>n;
        ll x=-INF;
        ll x1=-1;
        ll y=INF;
        ll y1=INF;
        ll ar[n];
        ll z=-1;
        ll neg=0;
        vector<ll>ze;
        vector<ll>nze;
        rep(i,n)
        {
            cin>>ar[i];
            if(ar[i]==0)
            {
                z=i;
                ze.pb(i+1);
            }
            else
            {
                nze.pb(i+1);
            }
            if(abs(ar[i])<y)
            {
                y=abs(ar[i]);
                y1=i;
            }
            if(ar[i]<0)
            {
                neg++;
            }
        }

        if(neg%2==1)
        {
            ll zz=-1;
            ll z11=INF;
            rep(i,n)
            {
                if(ar[i]<0&&z11>abs(ar[i]))
                {
                    z11=abs(ar[i]);
                    zz=i;
                }
            }
            ze.pb(zz+1);
            reverse(all(ze));
            vector<ll>v11;
            rep(i,nze.size())
            {
                if(nze[i]!=zz+1)
                {
                    v11.pb(nze[i]);
                }
            }
            nze.clear();
            if(!v11.empty())
            nze=v11;
        }
        // debug("AFSdfas");
        // rep(i,n)
        // {
        //     debug(ar[i]);
        // }
        {
            ll kk=0;
            // debug(kk);
            if(ze.empty())
            {
                kk=-1;
            }
            else
            {
                kk=ze.size()-1;   
            }
            // debug(kk);
            rep(i,kk)
            {
                cout<<"1 "<<ze[i]<<" "<<ze[kk]<<endl;
            }
            if(kk>=0&&ze.size()!=n)
            cout<<"2 "<<ze[kk]<<endl;
            ze.clear();
            
            ze=nze;
           
            kk=ze.size()-1;
            if(nze.size()==0)
                kk=0;
            // debug(kk);
            rep(i,kk)
            {
                cout<<"1 "<<ze[i]<<" "<<ze[kk]<<endl;
            }
        }





            return 0;

}