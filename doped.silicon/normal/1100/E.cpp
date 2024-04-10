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
ll n,m;
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
vector<pair<ll,ll> >v[100007];
vector<ll>mark;
vector<ll>ans;
ll kk=0;
void dfs(ll z,ll x)
{
    //debug(z);
    mark[z]=1;
    rep(i,v[z].size())
    {
        // debug(v[])
        if(mark[v[z][i].ff]==0&&v[z][i].ss>x)
        {
            //debug(v[z][i].ff);
            //debug(x);
            dfs(v[z][i].ff,x);
        }
        else if(mark[v[z][i].ff]==1&&v[z][i].ss>x)
        {
            //debug("DASf");
            //debug(v[z][i].ff);
            kk=1;
        }
    }
    mark[z]=2;
}
ll cycle(ll z)
{
    //debug("fd");
    //debug(z);
    mark.assign(n+1,0);
    kk=0;
    rep(i,n)
    {

        if(mark[i+1]==0)
        {
            //debug(i+1);
            dfs(i+1,z);
        }
    }
    if(kk)
        return 0;
    else return 1;
}
ll dfs1(ll n,ll z)
{
    mark[n]=1;
    rep(i,v[n].size())
    {
        if(mark[v[n][i].ff]==0&&v[n][i].ss>z)
            dfs1(v[n][i].ff,z);
    }
    ans.pb(n);
}
void topo(ll z)
{
    mark.assign(n+1,0);
    ans.clear();
    rep(i,n)
    {
        if(mark[i+1]==0)
            dfs1(i+1,z);
    }
    reverse(ans.begin(),ans.end());
}
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
            
            cin>>n>>m;
            vector<ll>k;
            ll hh[m][3];
            rep(i,m)
            {
                ll a,b,c;
                cin>>a>>b>>c;
                hh[i][0]=a;
                hh[i][1]=b;
                hh[i][2]=c;
                k.pb(c);
                v[a].pb(mp(b,c));
            }
            sort(k.begin(),k.end());
            ll mink=k[m-1];
            ll l=0,r=mink;
            while(r>=l)
            {
                ll mid=(l+r)/2;
                // ll mid=r--;
                //debug(mid);
                if(cycle(mid))
                {
                    mink=min(mink,mid);
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                //debug(mink);
            }
            topo(mink);
            ll sorted[n+1]={0};
            cout<<mink<<" ";
            ll rev=0;
            vector<ll>revd;
            ll f=ans.size();
            // debug(f);
            rep(i,ans.size())
            {
                // debug(ans[i]);
                sorted[ans[i]]=i+1;
            }
            rep(i,m)
            {
                if(hh[i][2]<=mink)
                {
                    if(hh[i][0]==0&&hh[i][1]==0)
                    {
                        sorted[(hh[i][0])]=++f;
                        sorted[(hh[i][1])]=++f;
                    }
                    else if(hh[i][0]==0)
                    {
                        sorted[(hh[i][0])]=++f;
                        rev++;
                        revd.pb(i+1);
                    }
                    else if(hh[i][1]==0)
                    {
                        sorted[(hh[i][1])]=++f;
                    }
                    else
                    {
                        if(sorted[hh[i][0]]>sorted[hh[i][1]])
                        {
                            rev++;
                            revd.pb(i+1);
                        }
                    }
                }
            }
            cout<<rev<<endl;
            rep(i,revd.size())
            {
                cout<<revd[i]<<" ";
            }

            
        return 0;
}