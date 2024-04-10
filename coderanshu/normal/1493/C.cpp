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

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> cnt(n+1,vector<int>(26));
    string s;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<26;++j)
            cnt[i][j] = cnt[i-1][j];
        ++cnt[i][s[i-1]-'a'];
    }
    bool good = true;
    for(int i=0;i<26;++i)
    {
        if(cnt[n][i]%k)
            good = false;
    }
    if(good)
    {
        cout<<s<<"\n";return 0;
    }
    for(int i=n;i>=1;--i)
    {
        // upto 1,i-1 is same
        int total = 0;
        int mx = -1;
        for(int j=0;j<26;++j)
        {
            if(cnt[i-1][j]%k)
            {
                total += k-cnt[i-1][j]%k;
                amax(mx,j);
            }
        }
        if(total > n-i+1)
            continue;
        if((n-i+1)%k != total % k)
            continue;
        if(s[i-1] == 'z')
            continue;
        if(total == (n-i+1) && mx <= (s[i-1]-'a'))
            continue;
        if(total == (n-i+1))
        {
            string t;
            bool got = false;
            char x=0;
            for(int j=0;j<26;++j)
            {
                if(cnt[i-1][j]%k)
                {
                    if(j>(s[i-1]-'a') && !got)
                    {
                        got = true;
                        int u = k - cnt[i-1][j]%k;
                        --u;
                        for(int k=0;k<u;++k)
                            t += char(j+'a');
                        x = char(j+'a');
                    }
                    else
                    {
                        int u = k - cnt[i-1][j]%k;
                        for(int k=0;k<u;++k)
                            t += char(j+'a');
                    }
                }
            }
            string ans;
            // assert(got && x>='a' && x<='z');
            for(int j=1;j<=i-1;++j)
                ans.pb(s[j-1]);
            ans += x + t;
            // assert(sz(ans) == n);
            cout<<ans<<"\n";
            return 0;
        }
        int rem = (n-i+1)-total;
        bool just = false;
        // cout<<rem<<"\n";
        if(cnt[i-1][(s[i-1]-'a')+1]%k)
        {
            just = true;
        }
        else
            cnt[i-1][(s[i-1]-'a')+1] += k,rem -= k;
        ++cnt[i-1][(s[i-1]-'a')+1];
        string ans;
        for(int j=1;j<=i-1;++j)
            ans.pb(s[j-1]);
        ans += (s[i-1]+1);
        // assert(rem % k == 0);
        for(int i=0;i<rem;++i)
            ans += 'a';
        for(int j=0;j<26;++j)
        {
            if(cnt[i-1][j]%k)
            {
                int u = k - cnt[i-1][j]%k;
                for(int k=0;k<u;++k)
                    ans += char(j+'a');
            }
        }
        // cout<<i<<"\n";
        // assert(sz(ans) == n);
        cout<<ans<<"\n";
        return 0;
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}