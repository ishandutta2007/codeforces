#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef gp_hash_table<long long, long long> umap;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define debug(x) cout<<x<<endl/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define endl '\n'
#define ll long long
#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
ll a[100005];
ll sum[100005];
ll c[100005][3];
ll f[300005];
ll ans=0;
ll an[100005];
ll blk=316;
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
bool alg(pair<pair<ll,ll>,ll > a,pair<pair<ll,ll>,ll > b)
{
    if(b.ff.ff/blk!=a.ff.ff/blk)
    {
        return a.ff.ff<b.ff.ff;
    }
    return
    a.ff.ss<b.ff.ss;
}

int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    cout<<setprecision(11);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n,k;
            cin>>n>>k;
            vector<ll>v;
            v.pb(0);
            v.pb(-k);
            v.pb(k);
            rep(i,n)
            {
                cin>>a[i];
            }
            rep(i,n)
            {
                ll x;
                cin>>x;
                if(a[i]==2)
                {
                    x*=-1;
                }
                sum[i+1]=sum[i]+x;
                x=sum[i+1];
                v.pb(x);
                v.pb(x+k);
                v.pb(x-k);
            }
            sort(v.begin(),v.end());
            unique(v.begin(),v.end());
            // debug(v.size());
            umap u;
            rep(i,v.size())
            {
                // debug(v[i]);
                u[v[i]]=i+1;
            }
            rep(i,n+1)
            {
                c[i][0]=u[sum[i]];
                // debug(u[sum[i]]);
                c[i][1]=u[sum[i]+k];
                // debug(u[sum[i]+k]);
                c[i][2]=u[sum[i]-k];

                // debug(u[sum[i]-k]);
            }
            ll l=1,r=0;
            ll q;
            cin>>q;
            vector<pair<pair<ll,ll>,ll > > v1;
            rep(i,q)
            {
                ll a,b;
                cin>>a>>b;
                v1.pb(mp(mp(a,b),i));
            }
            sort(all(v1),alg);
            rep(i,q)
            {
                ll a=v1[i].ff.ff;
                ll b=v1[i].ff.ss;
                while(r<b)
                {
                    r++;
                    ans+=f[c[r][2]];
                    f[c[r][0]]++;
                }
                while(l>=a)
                {
                    l--;
                    ans+=f[c[l][1]];
                    f[c[l][0]]++;
                }
                while(l+1<a)
                {
                    f[c[l][0]]--;
                    ans-=f[c[l][1]];
                    l++;   
                }
                while(r>b)
                {
                    f[c[r][0]]--;
                    ans-=f[c[r][2]];
                    r--;   
                }
                an[v1[i].ss]=ans;
            }
            rep(i,q)
            {
                cout<<an[i]<<endl;
            }
            return 0;
}