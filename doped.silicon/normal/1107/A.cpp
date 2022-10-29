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
    ll n;
    cin>>n;
    vector<ll>v;
    rep(i,n)
    {
        ll x;
        cin>>x;
        if(x==2)
        {
            char a,b;
            cin>>a>>b;
            if(b>a)
            {
                cout<<"YES"<<endl;
                cout<<"2"<<endl;
                cout<<a<<" "<<b<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            string s;
            cin>>s;
            cout<<"YES"<<endl;
            cout<<"2"<<endl;
            cout<<s[0]<<" ";
            for(ll i1=1;i1<x;i1++)
            {
                cout<<s[i1];
            }
            cout<<""<<endl;
        }
    }
    
    return 0;
}