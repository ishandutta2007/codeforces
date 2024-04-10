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
string he(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}
bool ar[5207][5207];
ll n;
bool check(ll x)
{
    // debug(x);
    bool val=1;
    for(ll i=0;i<n;i+=x)
    {
        for(ll j=0;j<n;j+=x)
        {
            bool t=ar[i][j];
            // debug(i);
            // debug(j);
            for(ll k1=i;k1<min(i+x,n);k1++)
            {
                for(ll k2=j;k2<min(j+x,n);k2++)
                {
                    // debug(min(k2+x,n));
                    // debug(k1);
                    // debug(k2);
                    if(ar[k1][k2]!=t)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>n;
    
    ll a=n;
    ll a1=1,b1=0;

    rep(i,n)
    {
        string s;
        cin>>s;
        ll k=0;
        rep(j,s.length())
        {
            string ss=he(s[j]);
            rep(jj,4ll)
            {
                if(ss[jj]=='1')
                ar[i][k]=1;
                else
                    ar[i][k]=0;
                k++;
            }
        }
    }
    rep(i,n)
    {
        ll len=0;
        rep(j,n)
        {
            if(ar[i][j])
                len++;
            else
                break;
        }
        a=min(a,len);
        if(a<i+1)
        {
            break;
        }
        a1=a;
    }
    rep(i,n)
    {
        ll len=0;
        rep(j,n)
        {
            if(!ar[i][j])
                len++;
            else
                break;
        }
        a=min(a,len);
        if(a<i+1)
        {
            break;
        }
        b1=a;
    }
    ll k=max(a1,b1);
    k=n;
    vector<ll>v;
    for(ll i=2;i*i<=k;i++)
    {
        if(k%i==0)
        {
            v.pb(i);
            if(k/i!=i)
            {
                v.pb(k/i);
            }
        }
    }
    v.pb(k);
    ll ans=1;
    rep(i,v.size())
    {
        // debug(v[i]);
        if(n%v[i]==0&&check(v[i]))
        {
            ans=max(ans,v[i]);
        }
    }
    cout<<ans;
    return 0;
}