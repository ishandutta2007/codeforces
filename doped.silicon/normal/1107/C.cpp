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
    long double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    vector<ll>v,v1;
    string s;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    cin>>s;
    v1.pb(v[0]);
    char p=s[0];
    ll ans=0;
    for(ll i=1;i<n;i++)
    {
        if(s[i]==p)
        {
            v1.pb(v[i]);
        }
        else
        {
            p=s[i];
            sort(v1.begin(),v1.end());
            reverse(v1.begin(),v1.end());
            ll pp=v1.size();
            ll z=min(pp,k);
            rep(j,z)
            {
                ans+=v1[j];
            }
            v1.clear();
            v1.pb(v[i]);
        }
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    ll pp=v1.size();
    ll z=min(pp,k);
    rep(j,z)
    {
        ans+=v1[j];
    }
    v1.clear();
    
    cout<<ans<<endl;
    return 0;
}