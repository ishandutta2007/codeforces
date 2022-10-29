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
#define INF 1000000000000000000
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

ll ar[8001];
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
            vector<ll>at,df,cl;
            set<ll>s;
            rep(i,n)
            {
                string s;
                ll x;
                cin>>s>>x;
                if(s=="ATK")
                    at.pb(x);
                else
                    df.pb(x);
            }
            rep(i,m)
            {
                ll x;
                cin>>x;
                cl.pb(x);
                ar[x]++;
                s.insert(x);
            }
            sort(at.begin(),at.end());
            sort(cl.begin(),cl.end());
            sort(df.begin(),df.end());
            if(m<=n)
            {
                ll ans=0;
                bool xx=true;
                for(ll i=1;i<=at.size()&&i<=cl.size()&&xx;i++)
                {
                    ll ind=cl.size()-i;
                    ll sum=0;
                    rep(j,i)
                    {
                        if(at[j]<=cl[ind])
                        {
                            sum+=cl[ind]-at[j];
                            ind++;
                        }
                        else
                        {
                            xx=false;
                            break;
                        }
                    }
                    if(xx)
                    {
                        ans=max(ans,sum);
                    }
                }
                cout<<ans<<endl;
            }
            else
            {
                ll ans=0;
                bool xx=true;
                for(ll i=1;i<=at.size()&&xx;i++)
                {
                    ll ind=cl.size()-i;
                    ll sum=0;
                    rep(j,i)
                    {
                        if(at[j]<=cl[ind])
                        {
                            sum+=cl[ind]-at[j];
                            ind++;
                        }
                        else
                        {
                            xx=false;
                            break;
                        }
                    }
                    if(xx)
                    {
                        ans=max(ans,sum);
                    }
                }
                if(xx)
                {
                rep(i,df.size())
                {
                    set<ll>::iterator it,ik;
                    ik=s.end();
                    ik--;
                    if(df[i]>*ik)
                    {
                        xx=false;
                        break;
                    }
                    it=upper_bound(s.begin(),s.end(),df[i]);
                    ar[*it]--;
                    if(ar[*it]==0)
                    {
                        s.erase(it);
                    }
                }}
                if(xx)
                {
                    set<ll>::iterator it,ik;
                    cl.clear();
                    for(it=s.begin();it!=s.end();it++)
                    {
                        while(ar[*it]--)
                        {
                            cl.pb(*it);
                        }
                    }
                    sort(cl.begin(),cl.end());
                    ll sum=0;
                    for(ll i=1;i<=at.size()&&xx;i++)
                    {
                        ll ind=cl.size()-i;
                         sum=0;
                        rep(j,i)
                        {
                            if(at[j]<=cl[ind])
                            {
                                sum+=cl[ind]-at[j];
                                ind++;
                            }
                            else
                            {
                                xx=false;
                                break;
                            }
                        }
                        if(xx)
                        {
                            ans=max(ans,sum);
                        }
                    }
                    if(xx)
                    {
                        rep(i,cl.size()-at.size())
                        {
                            sum+=cl[i];
                        }
                        ans=max(ans,sum);
                    }

                }
                cout<<ans<<endl;
            }
            return 0;
}