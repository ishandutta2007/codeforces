#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 205
#define mod ((ll)(998244353))

ll pascal[MAXN][MAXN];

void prep()
{
    pascal[0][1]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;
}

ll c(int i,int j)
{
    return pascal[i][j+1];
}

vector<ll> primes;

ll solve(ll x)
{
    vector<int> fs;
    ll sum=0,res=1;
    for(auto y : primes)
    {
        if(x%y==0)
        {
            int e=0;
            while(x%y==0)
            {
                e++;
                x/=y;
            }
            fs.push_back(e);
            sum+=e;
        }
    }

    for(auto y : fs)
    {
        res=(res*c(sum,y))%mod;
        sum-=y;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prep();

    ll d,q;
    cin >> d >> q;
    for(ll i=2;i<4e7;i++)
        while((d%i)==0)
        {
            if(primes.empty() || primes.back()!=i)
                primes.push_back(i);
            d/=i;
        }
    if(d!=1)
        primes.push_back(d);

    while(q--)
    {
        ll x,y;
        cin >> x >> y;
        ll xy=__gcd(x,y);
        db((solve(x/xy)*solve(y/xy))%mod)
    }

    return 0;
}