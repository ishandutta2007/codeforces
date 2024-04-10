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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll a[MAXN];
bool mk[(int)(2e8+5)];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        int x=abs(a[i]);
        for(int j=2;j*j<=x;j++)
        {
            int e=0;
            while((x%(j*j))==0)
                x/=(j*j);
        }
        if(a[i]<0)
            a[i]=-x;
        else
            a[i]=x;
        a[i]+=1e8+1;
    }

    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        int t[2];
        t[0]=0;
        t[1]=0;
        int diff=0;
        vector<int> vs;
        for(int j=i;j<n;j++)
        {
            if(a[j]<0)
                t[0]++;
            if(a[j]>0)
                t[1]++;
            if(!mk[abs(a[j])])
            {
                mk[abs(a[j])]=1;
                vs.push_back(a[j]);
                if(abs(a[j])!=(1e8+1))
                    diff++;
            }
            res[max(diff-1,0)]++;
        }
        for(auto y : vs)
            mk[y]=0;
    }
    for(auto y : res)
        cout << y << ' ';
    cout << '\n';

    return 0;
}