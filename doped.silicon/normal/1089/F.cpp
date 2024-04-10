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

ll gcd(ll a, ll b)
{
	if(b>a)
	{
		ll c = a;
		a = b;
		b = c;
	}
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll n;
    cin >> n;

    ll x[2];
    x[0] = 0;
    x[1] = 0;

    fr(i,2,sqrt(n))
    {
    	if(n%i==0)
    	{
    		if(gcd(i,n/i)==1)
    		{
    			x[0] = i;
    			x[1] = n/i;
    			break;
    		}
    	}
    }

    if(n==1 || n==2)
    {
    	cout << "NO" << endl;
    	return 0;
    }

    ll a = 1;

    if(x[0] == 0 && x[1] == 0)
    {
    	cout << "NO" << endl;
    	return 0;
    }

    bool poss = false;
    ll ans1 = 0;
    ll ans2 = 0;
    while(a*x[1]<(n-1))
    {
    	ll x2 = (n-1)-(a*x[1]);
    	if(x2%x[0]==0)
    	{
    		ans1 = a;
    		ans2 = x2/x[0];
    		poss = true;
    		break;
    	}
    	a++;
    }

    if(poss)
    {
    	cout << "YES" << endl;
    	cout << "2" << endl;
    	cout << ans1 << " " << x[0] << endl;
    	cout << ans2 << " " << x[1] << endl;
    }
    else
    	cout << "NO" << endl;
}