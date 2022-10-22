#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> res;
        int mid=(n-k)/2+1;
        res.push_back(mid);
        res.push_back(mid);
        for(int i=0;i<k-3;i++)
            res.push_back(1);
        res.push_back(n-mid*2-(k-3));
        if(res.back()==2)
        {
            if(mid&1)
            {
                if(mid!=1)
                {
                    res[0]--;
                    res[1]--;
                    if(k>4)
                    {
                        res[2]++;
                        res[3]++;
                    }
                    else
                    {
                        if(k==3)
                        {
                            if(n<16)
                                res[k-1]+=2;
                            else
                            {
                                res[0]=n/2;
                                res[1]=n/4;
                                res[2]=n/4;
                            }
                        }
                        else
                        {
                                res[0]=n/2;
                                res[1]=n/4;
                                res[2]=n/4;
                                res[3]=1;
                        }
                    }
                }
            }
        }

        for(auto x : res)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}