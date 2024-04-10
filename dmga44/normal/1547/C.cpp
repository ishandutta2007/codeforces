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
        int k,n,m;
        cin >> k >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        int pa=0;
        int pb=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push(pii(a[0],0));
        pq.push(pii(b[0],1));
        vector<int> acts;
        int sz=k;
        bool ok=1;
        while(!pq.empty())
        {
            pii x=pq.top();
            pq.pop();
            int p=x.f;
            int q=x.s;

            acts.push_back(p);
            if(p==0)
                sz++;
            else if(p>sz)
                ok=0;
            if(!q)
            {
                pa++;
                if(pa<n)
                    pq.push(pii(a[pa],0));
            }
            else
            {
                pb++;
                if(pb<m)
                    pq.push(pii(b[pb],1));
            }
        }

        if(!ok)
            db(-1)
        else
        {
            for(auto x : acts)
                cout << x << ' ';
            cout << '\n';
        }
    }


    return 0;
}