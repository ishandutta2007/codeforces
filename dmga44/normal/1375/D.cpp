#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
#define MAXN (ll)(1e3+5)

int a[MAXN];
bool mk[MAXN];
int n;

int mex()
{
    for(int i=0;i<=n;i++)
        mk[i]=0;
    for(int i=0;i<n;i++)
        mk[a[i]]=1;
    for(int i=0;i<=n;i++)
        if(!mk[i])
            return i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        vector<int> res;
        while(mex()!=n)
        {
            int x=mex();
            res.push_back(x);
            a[x]=x;
        }

        while(1)
        {
            int x=mex();
            if(x==n)
            {
                int p=-1;
                for(int i=n-1;i>=0;i--)
                    if(a[i]!=i)
                        p=i;
                if(p==-1)
                    break;
                res.push_back(p);
                a[p]=n;
            }
            else
            {
                res.push_back(x);
                a[x]=x;
            }
        }

        db(res.size())
        for(auto y : res)
            cout << y+1 << ' ';
        cout << '\n';
    }

    return 0;
}
/**
3
3
2 2 3
3
2 1 0
7
0 7 3 1 3 7 7
**/