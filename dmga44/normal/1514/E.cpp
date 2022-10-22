#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

string s[MAXN];

bool ask1(int a,int b)
{
    cout << "1 " << a << ' ' << b << '\n';
    cout.flush();
    int x=0;
//    x=s[a][b]-'0';
    cin >> x;
    return x==1;
}

bool ask2(int x,vector<int> ps)
{
    cout << "2 " << x << ' ' << ps.size();
    for(auto x : ps)
        cout << ' ' << x;
    cout << '\n';
    cout.flush();
    int xx=0;
    cin >> xx;
//    for(auto y : ps)
//        xx|=s[x][y]-'0';
    return xx==1;
}

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        int p1=0,p2=0;
        T ans;
        while(p1<v1.size() && p2<v2.size())
        {
            if(ask1(v1[p1],v2[p2]))
            {
                ans.push_back(v1[p1]);
                p1++;
            }
            else
            {
                ans.push_back(v2[p2]);
                p2++;
            }
        }
        while(p1<v1.size())
        {
            ans.push_back(v1[p1]);
            p1++;
        }
        while(p2<v2.size())
        {
            ans.push_back(v2[p2]);
            p2++;
        }

        return ans;
    }

    void build() { build(1,0,sz-1); }

    void build(int p,int l,int r)
    {
        if(l==r)
        {
            st[p]={l};
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid);
        build((p<<1)+1,mid+1,r);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }
};

void solve(int n)
{
//    for(int i=0;i<n;i++)
//        cin >> s[i];
    ST<vector<int>> st(n);
    st.build();

    vector<int> ord1=st.st[1];
    int lim=n-1;
    int ini=n-1;
    vector<vector<int>> scc;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> ta;
        for(int j=0;j<lim;j++)
            ta.push_back(ord1[j]);
        while(ask2(ord1[i],ta))
        {
            ta.pop_back();
            lim--;
        }
        if(lim==i)
        {
            vector<int> kk;
            for(int j=lim;j<=ini;j++)
                kk.push_back(ord1[j]);
            scc.push_back(kk);
            lim--;
            ini=lim;
        }
    }

    vector<int> be(n);
    for(int i=0;i<scc.size();i++)
        for(auto u : scc[i])
            be[u]=i;
    db(3)
    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<n;j++)
            cout << (int)(be[i]>=be[j]);
    cout.flush();
    int _;
    cin >> _;
}

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
        solve(n);
    }

    return 0;
}