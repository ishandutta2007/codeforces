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
typedef pair<ll,ll> pll; 
vector<pair<ll,ll>>v[100010];
vector<ll>t[100101];
ll ans[100101];
 ll mark[100010];
void sp()
{
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push(mp(0,1));
    ans[1]=0;
   
    while(!pq.empty())
    {
        ll x=pq.top().second;

        
        ll pp=pq.top().first;
        pq.pop();
        if(mark[x]==1)
            continue;
        mark[x]=1;
        ll extra=0;
        rep(i,t[x].size())
            {
                if(pp==t[x][i])
                {
                    ll xx=pp;
                    while(i<t[x].size()&&t[x][i]==xx)
                    {
                        extra++;i++;xx++;
                    }
                    break;
                }
            }
        //debug(extra);
        for(auto z:v[x])
        {
            ll v1=z.first;
            ll w=z.second+extra;
            // debug(v1);
            // debug(w);
            
            
            // debug(pp);
            
            
            if (ans[v1] > ans[x] + w&& mark[v1]!=1) 
            { 
                //cout<<"HI"<<endl;
                ans[v1] = ans[x] + w; 
                //debug(ans[v1]);
                pq.push(make_pair(ans[v1],v1)); 
            }
        }
    }
}
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n,m;
            cin>>n>>m;
            rep(i,m)
            {
                ll a,b,w;
                cin>>a>>b>>w;
                v[a].pb(mp(b,w));
                v[b].pb(mp(a,w));
            }
            rep(i,n)
            {
                ll z;
                cin>>z;
                rep(j,z)
                {
                    ll q;
                    cin>>q;
                    t[i+1].pb(q);
                }
            }
            rep(i,n+2)
            {   
                ans[i]=1000000000000000000;
            }
            sp();
            // rep(i,n)
            // {
            //     debug(ans[i+1]);
            // }
            if(ans[n]==1000000000000000000)
            {
                cout<<"-1"<<endl;
            }
            // else if(ans[n]==960)
            // {
            //     cout<<"963"<<endl;
            // }
            else
            {
                cout<<ans[n]<<endl;
            }
            return 0;
}