// Har Har Mahadev
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

    
const int MOD=MM;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};


const int N = 200005;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<ll> a(n+10),sum(n+10),sum_odd(n+10),sum_even(n+10);
    auto get = [&](int l,int r)
    {
        if(l > r)
            return 0ll;
        return sum[r] - sum[l-1];
    };
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
        sum_odd[i] = sum_odd[i-1];
        sum_even[i] = sum_even[i-1];
        if(i&1)
            sum_odd[i] += a[i];
        else
            sum_even[i] += a[i];
    }
    if(n == 1)
    {
        cout<<"1\n";return 0;
    }
    Mint ans = 0;
    ll C = 0,P = 0;
    // if first two are P
    if(n >= 2)
    {
        P += get(1,2);
        C += get(3,n);
        if(C < P)
            ++ans;
        for(int i=3;i<=n;++i)
        {
            P += a[i];
            C -= a[i];
            if(C < P)
                ++ans;
        }
    }
    // cout<<ans<<"\n";
    // auto check = [&](ll )
    // first is C
    C = 0,P = 0;
    C += a[1];
    for(int i=2;i<=n;++i)
    {
        // this is P
        {
            // agla bhi P
            {
                // last tak P
                ll u = get(i,n);
                if(u > C)
                    ++ans;
                if(i == 4)
                {
                    // cout<<u<<" "<<C<<"\n";
                    // cout<<ans<<"\n";
                }
                // last C
                if(i <= n-1)
                {
                    ll u = get(i,n-1);
                    if(u > C + a[n])
                        ++ans;
                }
            }
            // if(i == 2)
                // cout<<ans<<"\n";
            if(i+2 > n)
            {
                C += a[i];
                continue;
            }
            // agla C
            // CCCCCCCCCCCPC....... alternate and then think
            if(i <= n-1)
            {
                // binary search here
                // upto last
                int lo = i+1,hi = n-1,ff=-1;
                while(lo <= hi)
                {
                    int mid = (lo + hi)/2;
                    int cur = mid;
                    if(mid % 2 == i % 2)
                        --cur;
                    P += a[i];
                    ll ss = 0;
                    if(cur % 2 == 0)
                        ss = sum_even[cur] - sum_even[i];
                    else
                        ss = sum_odd[cur] - sum_odd[i];
                    C += ss;
                    P += get(cur+1,n);
                    P += get(i+1,cur) - ss;
                    // cout<<cur<<" "<<C<<" "<<P<<"\n";
                    if(C < P)
                        ff = cur,lo = mid+1;
                    else
                        hi = mid-1;
                    P -= a[i];
                    C -= ss;
                    P -= get(cur+1,n);
                    P -= get(i+1,cur) - ss;
                }
                if(ff != -1)
                {
                    int rem = ff - (i + 1) + 1;
                    ans += (rem + 1)/2;
                }
                // if(i == 2)
                    // cout<<ans<<"\n";
                // last if given to C
                if(i <= n-3)
                {
                    C += a[n];
                    // CCCCCCCCCCCCCPC..............C
                    int lo = i+1,hi = n-1,ff = -1;
                    // second last must be P ofc
                    if(hi % 2 != i % 2)
                        --hi;
                    while(lo <= hi)
                    {
                        int mid = (lo + hi)/2;
                        int cur = mid;
                        if(mid % 2 == i % 2)
                            --cur;
                        P += a[i];
                        ll ss = 0;
                        if(cur % 2 == 0)
                            ss = sum_even[cur] - sum_even[i];
                        else
                            ss = sum_odd[cur] - sum_odd[i];
                        C += ss;
                        P += get(cur+1,n-1);
                        P += get(i+1,cur) - ss;
                        if(C < P)
                            ff = cur,lo = mid+1;
                        else
                            hi = mid-1;
                        P -= a[i];
                        C -= ss;
                        P -= get(cur+1,n-1);
                        P -= get(i+1,cur) - ss;
                    }
                    if(ff != -1)
                    {
                        int rem = ff - (i + 1) + 1;
                        // if((n-1)%2 != i % 2)
                            // --ans;
                        ans += (rem+1)/2;
                    }

                    C -= a[n];
                }
                // if(i == 2)
                    // cout<<ans<<"\n";
            }
        }
        // if(i == 2)
            // cout<<ans<<"\n";
        C += a[i];
    }
    // cout<<ans<<"\n";
    // first is P second is C
    P = a[1];
    C = a[2];
    for(int i=3;i<=n;++i)
    {
        // i is firse P
        {
            // last tak P
            ll u = get(i,n);
            if(P + u > C)
                ++ans;

            if(i <= n-1)
            {
                ll u = get(i,n-1);
                if(P + u > C + a[n])
                    ++ans;
            }
        }
        // if(i == 3)
            // cout<<ans<<"\n";
        // now next i+1 C
        if(i+2>n)
        {
            C += a[i];
            continue;
        }
        // P += a[i];
        // binary search here
                // upto last
        int lo = i+1,hi = n-1,ff=-1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            int cur = mid;
            if(mid % 2 == i % 2)
                --cur;
            P += a[i];
            ll ss = 0;
            if(cur % 2 == 0)
                ss = sum_even[cur] - sum_even[i];
            else
                ss = sum_odd[cur] - sum_odd[i];
            C += ss;
            P += get(cur+1,n);
            P += get(i+1,cur) - ss;
            // cout<<cur<<" "<<C<<" "<<P<<"\n";
            if(C < P)
                ff = cur,lo = mid+1;
            else
                hi = mid-1;
            P -= a[i];
            C -= ss;
            P -= get(cur+1,n);
            P -= get(i+1,cur) - ss;
        }
        if(ff != -1)
        {
            int rem = ff - (i + 1) + 1;
            // int rem = n - ff + 1;
            // --ans;
            ans += (rem + 1)/2;
        }
        // if(i == 3)
        // {
        //     cout<<ff<<" ";
        //     cout<<ans<<"\n";
        // }
        // last if given to C
        if(i <= n-3)
        {
            C += a[n];
            // PCCCCCCCCCCCCCPC..............C
            int lo = i+1,hi = n-1,ff = -1;
            // second last must be P ofc
            if(hi % 2 != i % 2)
                --hi;
            while(lo <= hi)
            {
                int mid = (lo + hi)/2;
                int cur = mid;
                if(mid % 2 == i % 2)
                    --cur;
                P += a[i];
                ll ss = 0;
                if(cur % 2 == 0)
                    ss = sum_even[cur] - sum_even[i];
                else
                    ss = sum_odd[cur] - sum_odd[i];
                C += ss;
                P += get(cur+1,n-1);
                P += get(i+1,cur) - ss;
                if(C < P)
                    ff = cur,lo = mid+1;
                else
                    hi = mid-1;
                P -= a[i];
                C -= ss;
                P -= get(cur+1,n-1);
                P -= get(i+1,cur) - ss;
            }
            if(ff != -1)
            {
                int rem = ff - (i + 1) + 1;
                // if((n-1)%2 != i % 2)
                    // --ans;
                ans += (rem+1)/2;
            }

            C -= a[n];
        }        
        // if(i == 3)
            // cout<<ans<<"\n";
        // P -= a[i];
        C += a[i];
    }    
    if(C < P)
        ++ans;
    cout<<ans<<"\n";
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

// PPPPPP
// CPPPPP
// PCPPPP
// CCPPPP
// CPCPPP
// PCCPPP
// CCCPPP
// PCPCPP
// CCPCPP
// PCCCPP
// CPCPCP
// PPPPPC
// CPPPPC
// PCPPPC
// CCPPPC
// CPCPPC
// PPPPCC


// PCPPPP
// PCPPPC
// PCPCPP

// PCCCPP
// PCCPPP


// PPPPP
// CPPPP
// PCPPP
// CCPPP
// CPCPP
// PCCPP
// PPPPC
// CPPPC
// PCPPC
// CPCPC

// CPPPP
// CPCPP
// CPPPC
// CPCPC