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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin>>n;
    string s(n,'0');
    auto query = [&](string s)
    {
        cout<<"? "<<s<<"\n"<<flush;
        int x;
        cin>>x;
        return x;
    };
    int cur = query(s);
    int one_pos = -1,zero_pos = -1;
    function<void(int,int,string,int)> dfs = [&](int l,int r,string s,int val)
    {
        debug(l,r,s,val);
        if(l > r || (zero_pos != -1 && one_pos != -1))
            return ;
        if(l == r)
        {
            s[l] = '0'+'1'-s[l];
            int u = query(s);
            if(u < val)
            {
                if(s[l] == '1')
                    one_pos = l+1;
                else
                    zero_pos = l+1;
            }
            else
            {
                if(s[l] == '0')
                    one_pos = l+1;
                else
                    zero_pos = l+1;
            }
            return ;
        }
        if(r-l == 2)
        {
            dfs(l,r-1,s,val),dfs(l+1,r,s,val);
            return ;
        }
        int mid = (l + r)/2;
        if(mid == l)
            dfs(l,mid,s,val),dfs(mid+1,r,s,val);
        else
        {
            string t = s;
            for(int i=l;i<=mid;++i)
                t[i] = '1';
            int u = query(t);
            if(abs(u-val) == mid - l + 1)
            {
                if(u == val + mid - l + 1)
                    zero_pos = l+1;
                else
                    one_pos = l+1;
                dfs(mid+1,r,s,val);
            }
            else
            {
                dfs(l,mid,s,val);
            }
        }
    };
    dfs(0,n-1,s,cur);
    cout<<"! "<<zero_pos<<" "<<one_pos<<"\n"<<flush;
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