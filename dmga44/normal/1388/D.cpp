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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

ll a[MAXN];
ll b[MAXN];
int cant[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        if(b[i]!=-1)
        {
            b[i]--;
            cant[b[i]]++;
        }
    }

    ll ans=0;
    vector<int> res;
    queue<int> q;
    for(int i=0;i<n;i++)
        if(!cant[i])
            q.push(i);

    vector<int> re;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();

        if(a[i]>=0)
        {
            res.push_back(i);
            ans+=a[i];
            if(b[i]!=-1)
            {
                a[b[i]]+=a[i];
                cant[b[i]]--;
                if(!cant[b[i]])
                    q.push(b[i]);
            }
        }
        else
        {
            re.push_back(i);
            ans+=a[i];
            if(b[i]!=-1)
            {
                cant[b[i]]--;
                if(!cant[b[i]])
                    q.push(b[i]);
            }
        }
    }

    db(ans)
    for(auto y : res)
        cout << y+1 << ' ';
    reverse(all(re));
    for(auto y : re)
        cout << y+1 << ' ';
    cout << '\n';


    return 0;
}
/**
10
-10 -1 2 2 5 -2 -3 -4 2 -6
-1 -1 2 2 -1 5 5 7 7 9
**/