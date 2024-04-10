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
int n,m;
 int mat[1507][1507];
 int mark[1507][1507][2];
void dfs(int x,int y)
{
    ll x1=(x+1000000*n)%n;
    ll y1=(y+1000000*m)%m;
    
    // dbug(x,y);
    // dbug(x1,y1);
    if(mat[x1][y1]==0)
    {return; 
    }
    if(mark[x1][y1][0]==x&&mark[x1][y1][1]==y)
    {
        return;
    }
    if(mark[x1][y1][0]!=-1||mark[x1][y1][0]!=-1)
    {
        cout<<"YES";
        exit(0);
    }
    else
    {
        mark[x1][y1][0]=x;
        mark[x1][y1][1]=y;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
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
        cin>>n>>m;
        rep(i,1507)
        {
            rep(j,1507)
            {
                rep(k,2)
                {
                    mark[i][j][k]=-1;
                }
            }
        }
        ll x=-1,y=-1;
        rep(i,n)
        {
            rep(j,m)
            {
                char c;
                cin>>c;
                if(c=='S')
                {
                    x=i;
                    y=j;
                    mat[i][j]=1;
                }
                else if(c=='.')
                {
                    mat[i][j]=1;
                }
            }
        }
        dfs(x,y);
        // if(z)
        // cout<<"Yes";
        // else
        cout<<"No";
        return 0;
}