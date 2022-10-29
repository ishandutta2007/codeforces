#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000000000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long double pi= 3.14159265358979323846;
    ll n,m;
    cin>>n>>m;
    vector<ll>v[n+1];
    ll mark[n+1]={0};
    priority_queue<ll, vector<ll>, greater<ll> > pq; 
    rep(i,m)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    pq.push(1);
    mark[1]=1;
    while(!pq.empty())
    {

        ll x=pq.top();
        pq.pop();
        cout<<x<<" ";
        rep(i,v[x].size())
        {
            if(!mark[v[x][i]])
            {
                pq.push(v[x][i]);
                mark[v[x][i]]=1;
            }
        }
    }
    return 0;
}