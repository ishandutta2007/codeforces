#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> primes[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!primes[i].size())
            for(int j=i;j<MAXN;j+=i)
                primes[j].push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    vector<int> sp;
    for(int i=2;i<MAXN;i++)
    {
        if(primes[i].size()>2)
            continue;
        if(primes[i].size()==2)
        {
            if(primes[i][0]*primes[i][1]==i)
                sp.push_back(i);
        }
        else
        {
            if(primes[i][0]==i || primes[i][0]*primes[i][0]==i)
                sp.push_back(i);
        }
    }

    bitset<MAXN> mk;
    for(auto y : sp)
        mk[y]=1;

    int n,f;
    cin >> n >> f;
    mk[f]=0;
    vector<int> grundies(MAXN);
    vector<bitset<MAXN>> cc(100);
    for(int i=0;i<MAXN;i++)
    {
        while(cc[grundies[i]][i])
            grundies[i]++;
        cc[grundies[i]]|= mk<<i;
    }

    int g=0;
    for(int i=0;i<n;i++)
    {
        int b,w,r;
        cin >> b >> w >> r;
        int d1=w-b-1;
        int d2=r-w-1;
        g^=grundies[d1];
        g^=grundies[d2];
    }

    if(g)
    {
        db("Alice")
        db("Bob")
    }
    else
    {
        db("Bob")
        db("Alice")
    }

    return 0;
}