#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

struct SAT
{
    int n;
    vector<int> a;
    vector<vector<int>> g,rg;

    SAT(){}

    SAT(int n_):n(n_)
    {
        a.resize(2*n+1);
        g.resize(2*n+1);
        rg.resize(2*n+1);
    }
    void add_edge(int x,int y,bool negx,bool negy)
    {
        // cout<<x<<" "<<y<<" "<<negx<<" "<<negy<<"\n";
        --x,--y;
        x *= 2,y *= 2;
        if(negx)
            x ^= 1;
        if(negy)
            y ^= 1;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    bool solve()
    {
        vector<int> order;
        vector<bool> vis(2*n+1,0);
        vector<int> comp(2*n+1,0);
        function<void(int)> dfs1 = [&](int u)
        {
            vis[u] = true;
            for(auto j:g[u])
                if(!vis[j])
                    dfs1(j);
            order.push_back(u);
        };
        for(int i=0;i<2*n;++i)
            if(!vis[i])
                dfs1(i);
        reverse(order.begin(),order.end());
        int cur = 1;

        function<void(int,int)> dfs = [&](int u,int cmp)
        {
            comp[u] = cmp;
            for(auto j:rg[u])
                if(comp[j] == 0)
                    dfs(j,cmp);
        };
        for(int i:order)
        {
            if(comp[i] == 0)
                dfs(i,cur++);
        }
        for(int i=0;i<n;++i)
        {
            int j = i * 2;
            if(comp[j] == comp[j+1])
                return false;
        }
        return true;
    }
};

struct node {
    int x,y;
    char c,cc;
};

int _runtimeTerror_()
{
    int n,m;
    string s;
    cin>>s;
    cin>>n>>m;
    int l = s.size();
    // V -> false C -> true
    vector<node> v(m);
    for(int i=0;i<m;++i)
        cin>>v[i].x>>v[i].c>>v[i].y>>v[i].cc;

    string word;
    cin>>word;

    int lo = 0,hi = n,ans = -1;
    auto f = [&](int x)
    {
        SAT sat(n);
        for(auto [x,y,c,cc]:v)
        {
            sat.add_edge(x,y,c!='V',cc!='V');
            sat.add_edge(y,x,cc=='V',c=='V');
        }
        for(int i=0;i<x;++i)
        {
            if(s[word[i]-'a'] == 'V')
                sat.add_edge(i+1,i+1,1,0);
            else
                sat.add_edge(i+1,i+1,0,1);
        }
        auto ans = sat.solve();
        return ans;
    };
    for(int i=n;i>=0;--i)
    {
        if(f(i))
        {
            if(i == n)
            {
                cout<<word<<"\n";return 0;
            }
            char u = word[i];
            set<char> done;
            int cnt = 0;
            for(char c = u+1;c<='z';++c)
            {
                if(c - 'a' >= l)
                    break;
                if(done.count(s[c-'a']))
                    continue;
                done.insert(s[c-'a']);
                ++cnt;
                assert(cnt <= 2);
                word[i] = c;
                if(f(i+1))
                {
                    // good
                    char x = 0,y = 0;
                    for(int j=l-1;j>=0;--j)
                    {
                        if(s[j] == 'V')
                            x = char(j+'a');
                        if(s[j] == 'C')
                            y = char(j+'a');
                    }
                    if(x == 0 || y == 0)
                    {
                        for(int j=i+1;j<n;++j)
                            word[j] = 'a';
                        if(f(n))
                            cout<<word<<"\n";
                        else
                            cout<<"-1\n";
                        return 0;
                    }
                    if(x > y)
                        swap(x,y);
                    for(int j=i+1;j<n;++j)
                    {
                        word[j] = x;
                        if(f(j+1))
                            continue;
                        word[j] = y;
                    }
                    cout<<word<<"\n";return 0;
                }
            }
        }
    }
    cout<<"-1\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}