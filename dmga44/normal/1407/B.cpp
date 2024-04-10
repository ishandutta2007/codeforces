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
typedef double ld;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<int> divs[MAXN];

void criba()
{
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            divs[j].push_back(i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();
    for(int i=0;i<MAXN;i++)
        reverse(all(divs[i]));

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> fs(MAXN);
        int ma=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            fs[x]++;
            ma=max(ma,x);
        }

        vector<int> res;
        for(int i=0;i<fs[ma];i++)
            res.push_back(ma);
        fs[ma]=0;
        int x=ma;
        while(1)
        {
            int nex=-1;
            for(auto d : divs[x])
            {
                int sum=0;
                for(int i=d;i<MAXN;i+=d)
                    sum+=fs[i];
                if(sum)
                {
                    nex=d;
                    break;
                }
            }
            if(nex==-1)
                break;

            for(int i=nex;i<MAXN;i+=nex)
            {
                for(int j=0;j<fs[i];j++)
                    res.push_back(i);
                fs[i]=0;
            }
            x=nex;
        }

        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}