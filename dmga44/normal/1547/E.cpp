//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
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
        vector<int> ps(k);
        vector<int> ts(k);
        vector<bool> mk(n);
        vector<int> ans(n);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<k;i++)
        {
            cin >> ps[i];
            ps[i]--;
        }
        for(int i=0;i<k;i++)
        {
            cin >> ts[i];
            pq.push(pii(ts[i],ps[i]));
        }

        while(!pq.empty())
        {
            pii x=pq.top();
            pq.pop();

            int te=x.f;
            int p=x.s;

            if(mk[p])
                continue;
            mk[p]=1;
            ans[p]=te;
            if(p)
                pq.push(pii(te+1,p-1));
            if(p+1<n)
                pq.push(pii(te+1,p+1));
        }

        for(int i=0;i<n;i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }


    return 0;
}