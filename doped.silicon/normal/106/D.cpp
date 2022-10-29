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
ll a[1002][1002];
ll s[26][2];
ll W[1002][1002];
ll N[1002][1002];
ll E[1002][1002];
ll S[1002][1002];
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
            rep(i,1002)
            {
                rep(j,1002)
                {
                    a[i][j]=-1;
                }
            }
            rep(i,n)
            {
                rep(j,m)
                {
                    char c;
                    cin>>c;
                    if(c=='#')
                        a[i+1][j+1]=-1;
                    else if(c=='.')
                    {
                        a[i+1][j+1]=0;
                    }
                    else
                    {
                        a[i+1][j+1]=0;
                        s[c-'A'][0]=i+1;
                        s[c-'A'][1]=j+1;
                    }
                }
            }
            for(ll i=1;i<=n;i++)
            {
                for(ll j=1;j<=m;j++)
                {
                    if(a[i][j-1]==-1)
                        W[i][j]=0;
                    else
                    {
                        W[i][j]=W[i][j-1]+1;
                    }
                }
            }
            for(ll i=1;i<=n;i++)
            {
                for(ll j=m;j>0;j--)
                {
                    if(a[i][j+1]==-1)
                        E[i][j]=0;
                    else
                    {
                        E[i][j]=E[i][j+1]+1;
                    }
                }
            }
            for(ll i=1;i<=m;i++)
            {
                for(ll j=n;j>0;j--)
                {
                    if(a[j+1][i]==-1)
                        S[j][i]=0;
                    else
                    {
                        S[j][i]=S[j+1][i]+1;
                    }
                }
            }
            for(ll i=1;i<=m;i++)
            {
                for(ll j=1;j<=n;j++)
                {
                    if(a[j-1][i]==-1)
                        N[j][i]=0;
                    else
                    {
                        N[j][i]=N[j-1][i]+1;
                    }
                }
            }
            // rep(i,n)
            // {
            //     rep(j,m)
            //     {
            //         cout<<a[i+1][j+1]<<" ";
            //     }
            //     cout<<""<<endl;
            // }
            // rep(i,n)
            // {
            //     rep(j,m)
            //     {
            //         cout<<S[i+1][j+1]<<" ";
            //     }
            //     cout<<""<<endl;
            // }
            ll k=0;
            cin>>k;
            vector<pair<char,ll> >v;
            rep(i,k)
            {
                ll x;
                char chk;
                cin>>chk;
                //debug(chk);
                cin>>x;
                v.pb(mp(chk,x));
                //debug(v[i].ff);
            }
            vector<char>ch;
            rep(i,26)
            {
                ll z=1;
                ll x=s[i][0];
                ll y=s[i][1];
                if(x==0&&y==0)
                {
                    z=0;
                }
                else
                {
                rep(j,k)
                {
                    //dbug(x,y);
                    //debug(v[j].ff);
                    if(v[j].ff=='N')
                    {
                        //debug(N[x][y]);
                        if(N[x][y]>=v[j].ss)
                        x=x-v[j].ss;
                        else 
                        {
                            z=0;
                            break;
                        }
                    }

                    else if(v[j].ff=='S')
                    {
                        //debug(S[x][y]);
                        if(S[x][y]>=v[j].ss)
                        x=x+v[j].ss;
                        else 
                        {
                            z=0;
                            break;
                        }
                    }
                    else if(v[j].ff=='E')
                    {
                        if(E[x][y]>=v[j].ss)
                        y=y+v[j].ss;
                        else 
                        {
                            z=0;
                            break;
                        }
                    }
                    else if(v[j].ff=='W')
                    {
                        if(W[x][y]>=v[j].ss)
                        y=y-v[j].ss;
                        else 
                        {
                            z=0;
                            break;
                        }
                    }
                }
                //debug(z);
                if(z)
                {
                    ch.pb('A'+i);
                }
                }
                
            }
            rep(i,ch.size())
            {
                cout<<ch[i];
            }
            if(ch.size()==0)
            {
                cout<<"no solution";
            }
            return 0;
}