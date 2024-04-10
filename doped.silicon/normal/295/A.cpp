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
    
    long double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,m,k;
    cin>>n>>m>>k;
    ll ar[n];
    ll op[m][3];
    ll fun1[n+1]={0};
    ll fun2[m+1]={0};   
    rep(i,n)
    {
        cin>>ar[i];
    }
    rep(i,m)
    {
        cin>>op[i][0]>>op[i][1]>>op[i][2];
          // debug(i);
    }
    ll a,b;
    rep(i,k)
    {
        cin>>a>>b;
        fun2[a-1]+=1;
        fun2[b]-=1;
    }
    ll sum=0;
    rep(i,m)
    {
        sum+=fun2[i];
        a=op[i][0];
        b=op[i][1];
        fun1[a-1]+=op[i][2]*sum;
        fun1[b]-=op[i][2]*sum;
    }
    sum=0;
    rep(i,n)
    {
        sum+=fun1[i];
        cout<<sum+ar[i]<<' ';
    }
    return 0;
}