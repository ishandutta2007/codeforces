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
ll mark[100010];
vector<ll>v;
vector<ll>v1[100010];
ll graph[600][600];
vector<ll>chk;
void floydWarshall (ll V) 
{ 
    ll dist[V][V], i, j, k; 
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
    rep(i,V)
    {
        rep(j,V)
        {
            if(dist[i][j]==INF)
                cout<<"-1 ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<""<<endl;
    }
} 

void check(ll n)
{
    mark[n]=1;
    chk.pb(n);
    rep(i,v1[n].size())
    {
        if(mark[v1[n][i]]==0)
        {
            check(v1[n][i]);
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
            ll n,m,k;
            cin>>n>>m>>k;
            ll cost[k+2];
            
            ll sum=0;
            rep(i,k)
            {   
                ll x;
                cin>>x;
                cost[i+1]=x;
                sum+=x;
                v.pb(sum);
            }
            rep(i,k)
            {
                rep(j,k)
                {
                    if(i!=j)
                    graph[i][j]=INF;
                }
            }
            rep(i,n)
            {
                v1[i+1].pb(i+1);
            }
            rep(i,m)
            {
                ll x,y,z;
                cin>>x>>y>>z;
                vector<ll>::iterator lb1,lb2;
                lb1=lower_bound(v.begin(),v.end(),x);
                lb2=lower_bound(v.begin(),v.end(),y);
                graph[lb1-v.begin()][lb2-v.begin()]=min(graph[lb1-v.begin()][lb2-v.begin()],z);
                graph[lb2-v.begin()][lb1-v.begin()]=min(graph[lb2-v.begin()][lb1-v.begin()],z);
                if(z==0)
                {
                    v1[x].pb(y);
                    v1[y].pb(x);
                }
            }
            //debug(n);
            bool z=true;
            rep(i,n)
            {
                //debug(i);
                set<ll>s;
                if(mark[i+1]==0)
                {
                    check(i+1);
                    //debug(chk[0]);
                    sort(chk.begin(),chk.end());
                    rep(i,chk.size())
                    {
                        ll x=chk[i];
                        vector<ll>::iterator lb; 
                        lb=lower_bound(v.begin(),v.end(),x);
                        //debug(lb-v.begin());
                        cost[lb-v.begin()+1]--;
                        s.insert(lb-v.begin()+1);
                    }
                    set <ll>::iterator it;
                    for(it = s.begin();it != s.end();++it)
                    {
                        //debug(*it);
                        if(cost[*it]!=0)
                        {
                            z=false;
                        }
                    }
                    if(!z)
                    {
                        break;
                    }
                }
                chk.clear();
            }
            if(z)
            {
                cout<<"Yes"<<endl;
                floydWarshall (k);
            }
            else
                cout<<"No"<<endl;
            return 0;
}