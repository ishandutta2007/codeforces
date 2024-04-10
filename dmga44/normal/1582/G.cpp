#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

int abi[MAXN];

void update(int p,int v)
{
    p++;
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int bs()
{
    int ans=0;
    for(int po=(1<<19);po;po>>=1)
        if(ans+po<MAXN && !abi[ans+po])
            ans+=po;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n;
    cin >> n;
    vector<int> a(n);
    int cont=0;
    vector<int> trans(MAXN);
    for(int i=2;i<MAXN;i++)
        if(p[i]==i)
        {
            trans[i]=cont;
            cont++;
        }
    vector<stack<pii>> vst(cont);
    // vector<pii>> lims(MAXN);
    for(int i=0;i<n;i++)
        cin >> a[i];

    string s;
    cin >> s;
    vector<vector<pii>> des(n);
    for(int i=0;i<n;i++)
    {
        int mul=1;
        if(s[i]=='/')
            mul=-1;
        
        while(a[i]!=1)
        {
            int e=0;
            int pr=p[a[i]];
            while((a[i]%pr)==0)
            {
                e++;
                a[i]/=pr;
            }
            des[i].push_back(pii(pr,mul*e));
        }
    }

    vector<int> act(MAXN);

    for(int i=2;i<MAXN;i++)
        if(p[i]==i)
        {
            int pos=trans[i];
            vst[pos].push(pii(-1e9,n+1));
            // vst[i].push(pii(0,n));
            // update(n,1);
        }
    update(n+1,1);
    // cout << bs() << '\n';

    ll ans=0;
    vector<int> vis(MAXN);
    for(int i=n-1;i>=0;i--)
    {
        for(auto y : des[i])
        {
            int p=y.first;
            p=trans[p];
            if(!vis[p])
            {
                vst[p].push(pii(0,i+1));
                update(n+1,1);
                vis[p]=1;
            }
            vst[p].top().second=i+1;
            int e=y.second;

            act[p]-=e;

            pii too=vst[p].top();
            vst[p].pop();
            update(vst[p].top().second,-1);
            vst[p].push(too);
            
            while(vst[p].top().first>=act[p])
                vst[p].pop();
            
            update(vst[p].top().second,1);
            
            // cout << i << ' ' << p << ' ' << vst[p].top().second << '\n';
            vst[p].push(pii(act[p],i));
        }
        // cout << s[i] << ' ' << i << ' ' << bs() << '\n';
        ans+=bs()-i-1;
    }

    cout << ans << '\n';

    return 0;   
}