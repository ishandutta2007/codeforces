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
ll mi[300010][(ll)log2(300010)+5];
ll gc[300010][(ll)log2(300010)+5];
ll ar[300010];
ll n;
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
void buildmin()
{
    for(ll i=n-1;i>=1;i--)
    {
        
        for(ll j=1;pow(2,j)<=n-i+1;j++)
        {
            mi[i][j]=min(mi[i][j-1],mi[i+(ll)pow(2,j-1)][j-1]);
            
        }
    }
}
void buildgcd()
{
    for(ll i=n-1;i>=1;i--)
    {
        for(ll j=1;pow(2,j)<=n-i+1;j++)
        {
            gc[i][j]=gcd(gc[i][j-1],gc[i+(ll)pow(2,j-1)][j-1]);
        }
    }
}
ll qmin(ll l,ll r)
{
    ll j = (ll)log2(r-l+1);
    return min(mi[l][j],mi[r-(1<<j)+1][j]);
}
ll qgcd(ll l,ll r)
{
    ll j = (ll)log2(r-l+1);
    return gcd(gc[l][j],gc[r-(1<<j)+1][j]);
}
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
            
            cin>>n;
            rep(i1,n)
            {
                ll i=i1+1;
                cin>>ar[i];
                mi[i][0]=ar[i];
                gc[i][0]=ar[i];
            }
            buildgcd();
            buildmin();
            
            ll l=1,r=n;
            ll ans=0;
            vector<ll>v1,v2;
            while(l<=r)
            {

                v1.clear();
                ll mid=(l+r)/2;
                ll i=1;
                ll j=mid;
                // debug(mid);
                while(j<=n)
                {
                    // debug(i);
                    // debug(j);
                    // debug(qgcd(i,j));
                    // debug(qmin(i,j));
                    if(qgcd(i,j)==qmin(i,j))
                    {
                        // //debug(i);
                        // cout<<"HI"<<endl;
                        v1.pb(i);
                    }
                    j++;
                    i++;
                }
                if(v1.size()>=1)
                {
                    ans=(mid)-1;
                    v2.clear();
                    v2=v1;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }

            }
            cout<<v2.size()<<" "<<ans<<endl;
            rep(i,v2.size())
            {
                cout<<v2[i]<<" ";
            }
            return 0;
}