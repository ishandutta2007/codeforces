#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> primes;
bool p[MAXN];
bool mk[MAXN];
int cant;
int n;

void kill(int x)
{
    for(int i=x;i<=n;i+=x)
        if(!mk[i])
        {
            cant--;
            mk[i]=1;
        }
}

int contt(int x)
{
    int res=0;
    for(int i=x;i<=n;i+=x)
        if(!mk[i])
            res++;
    return res;
}

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
        {
            primes.push_back(i);
            for(int j=i;j<MAXN;j+=i)
                p[j]=1;
        }
}

int aska(int x)
{
    cout << "A " << x << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void askb(int x)
{
    cout << "B " << x << '\n';
    cout.flush();
    int res;
    cin >> res;
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    criba();
    cin >> n;
    cant=n;
    vector<int> ap;
    while(!primes.empty() && primes.back()>n)
        primes.pop_back();

    int lim=0;
    bool done=0;
    int res;
    for(int i=0;i<primes.size();i++)
    {
        askb(primes[i]);
        kill(primes[i]);
        if(i%30==29)
        {
            int v=aska(1);
            if(v==cant)
                lim=primes[i];
            else
            {
                done=1;
                vector<int> pdivs;
                for(int i=0;i<primes.size();i++)
                    if(primes[i]>lim)
                    {
                        int x=aska(primes[i]);
                        int x2=contt(primes[i]);
                        if(x!=x2)
                            pdivs.push_back(primes[i]);
                    }

                for(int i=0;i<pdivs.size();i++)
                {
                    ll base=pdivs[i];
                    ll mul=base*base;
                    while(mul<=n)
                    {
                        int x=aska(mul);
                        int x2=contt(mul);
                        if(x!=x2)
                        {
                            pdivs[i]=mul;
                            mul*=base;
                        }
                        else
                            break;
                    }
                }
                res=1;
                for(auto y : pdivs)
                    res*=y;

                break;
            }
        }
    }
    if(!done)
    {
        int v=aska(1);
        if(v!=cant)
        {
            done=1;
            vector<int> pdivs;
            for(int i=0;i<primes.size();i++)
                if(primes[i]>lim)
                {
                    int x=aska(primes[i]);
                    int x2=contt(primes[i]);
                    if(x!=x2)
                        pdivs.push_back(primes[i]);
                }

            for(int i=0;i<pdivs.size();i++)
            {
                ll base=pdivs[i];
                ll mul=base*base;
                while(mul<=n)
                {
                    int x=aska(mul);
                    int x2=contt(mul);
                    if(x!=x2)
                    {
                        pdivs[i]=mul;
                        mul*=base;
                    }
                    else
                        break;
                }
            }
            res=1;
            for(auto y : pdivs)
                res*=y;
        }
    }

    if(done)
    {
        cout << "C " << res << '\n';
        cout.flush();
    }
    else
    {
        cout << "C " << 1 << '\n';
        cout.flush();
    }

    return 0;
}