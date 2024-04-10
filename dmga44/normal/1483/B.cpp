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
const ll mod=(ll)(998244353);
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
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<int> blk(n);
        vector<int> nex(n);
        deque<int> blocks[n];
        for(int i=0;i<n;i++)
        {
            blk[i]=i;
            nex[i]=i+1;
            blocks[i].push_back(i);
        }
        nex[n-1]=0;

        int act=0,cant=n;
        vector<int> ans;
        while(1)
        {
            if(blocks[blk[act]].size()==cant)
                break;
//            db("")
//            db(act)
            int id1=blocks[blk[act]].front();
            int id2=nex[id1];
//            cout << id1 << ' ' << id2 << '\n';
            if(__gcd(a[id1],a[id2])==1)
            {
//                db("kill")
                blocks[blk[nex[id1]]].pop_back();
                ans.push_back(id2);
                nex[id1]=nex[id2];
                cant--;
                act=nex[id1];
            }
            else
            {
//                db("join")
                if(blocks[blk[act]].size()<blocks[blk[nex[id1]]].size())
                {
                    int bl=blk[act];
                    while(!blocks[bl].empty())
                    {
                        int u=blocks[bl].front();
                        blocks[bl].pop_front();
                        blk[u]=blk[nex[id1]];
                        blocks[blk[nex[id1]]].push_back(u);
                    }
                }
                else
                {
                    int bl=blk[nex[id1]];
                    while(!blocks[bl].empty())
                    {
                        int u=blocks[bl].back();
                        blocks[bl].pop_back();
                        blk[u]=blk[act];
                        blocks[blk[act]].push_front(u);
                    }
                }
            }
        }

//        for(int i=0;i<n;i++)
//        {
//            cout << i << ' ';
//            for(auto x : blocks[i])
//                cout << x << ' ';
//            cout << '\n';
//        }

        int bl=blk[act];
        while(!blocks[bl].empty() && __gcd(a[blocks[bl].front()],a[blocks[bl].back()])==1)
        {
            ans.push_back(blocks[bl].back());
            blocks[bl].pop_back();
        }

//        db("xxx")
        cout << ans.size() << ' ';
        for(auto x : ans)
            cout << x+1 << ' ';
        cout << '\n';
    }

    return 0;
}