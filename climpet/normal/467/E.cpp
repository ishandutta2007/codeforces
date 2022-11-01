#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8



typedef unsigned long long ull;

struct barray{
    vector<ull> v;
    vector<unsigned> cnt;
    barray(const vector<ull> &w) : v(w){
        int n = v.size();
        cnt.assign(n + 1, 0);
        for(size_t i = 1; i < cnt.size(); ++i){
            cnt[i] = cnt[i - 1] + __builtin_popcountll(v[i - 1]);
        }
    }
    unsigned rank(unsigned x){
        unsigned y = x / 64;
        return cnt[y] + __builtin_popcountll(v[y] & ((1ull << (x % 64)) - 1));
    }
};

struct wavelet{
    vector<barray> vs;
    unsigned n;
    wavelet(vector<int> z) : n(z.size()){
        vs.reserve(20);
        vector<ull> w((n + 63) / 64);
        for(int h = 20; h--; ){
            for(unsigned i = 0; i < n; ++i){
                if(z[i] >> h & 1){
                    w[i / 64] |= 1ull << (i % 64);
                }
                else{
                    w[i / 64] &= ~(1ull << (i % 64));
                }
            }
            vs.emplace_back(w);

            stable_sort(ALL(z), [=](int x, int y){ return (x >> h) < (y >> h); });
        }
    }
    
    unsigned ltrmq(unsigned l, unsigned r, unsigned v){
        return ltrmq(l, r, v, 0, n, 0, 20);
    }

    unsigned ltrmq(
        unsigned l, unsigned r, unsigned v,
        unsigned p, unsigned q, unsigned vm, int h
    ){
        int lv = 20 - h;
        for( ; h--; ++lv){
            unsigned c1r = vs[lv].rank(r);
            unsigned c1l = vs[lv].rank(l);
            unsigned c0r = r - c1r;
            unsigned c0l = l - c1l;
            unsigned c1p = vs[lv].rank(p);
            unsigned c0p = p - c1p;
            unsigned c1q = vs[lv].rank(q);
            unsigned c0q = q - c1q;

            if((vm | 1u << h) < v && c1l < c1r){
                unsigned ret = ltrmq(
                    p + (c0q - c0p) + (c1l - c1p),
                    p + (c0q - c0p) + (c1r - c1p),
                    v, p + (c0q - c0p), q,
                    vm | 1u << h, h
                );
                if(~ret){ return ret; }
            }
            if(c0l >= c0r){ return ~0u; }
            l = p + (c0l - c0p);
            r = p + (c0r - c0p);
            q = p + (c0q - c0p);
        }
        return vm;
    }
    
    unsigned lessthan(unsigned l, unsigned r, int v){
        unsigned res = 0;
        int lv = 0;
        unsigned p = 0, q = n;
        for(int h = 20; h--; ++lv){
            unsigned c1r = vs[lv].rank(r);
            unsigned c1l = vs[lv].rank(l);
            unsigned c0r = r - c1r;
            unsigned c0l = l - c1l;
            unsigned c1p = vs[lv].rank(p);
            unsigned c0p = p - c1p;
            unsigned c1q = vs[lv].rank(q);
            unsigned c0q = q - c1q;

            if(v >> h & 1){
                res += c0r - c0l;
                l = p + (c0q - c0p) + (c1l - c1p);
                r = p + (c0q - c0p) + (c1r - c1p);
                p = p + (c0q - c0p);
            }
            else{
                l = p + (c0l - c0p);
                r = p + (c0r - c0p);
                q = p + (c0q - c0p);
            }
        }
        return res;
    }
};


int main(){
    int m;
    scanf("%d", &m);
    
    vint a(m + 1);
    vint prv(m + 1), nxt(m + 1);
    map<int,int> mp;
    for(int i = 1; i <= m; ++i){
        scanf("%d", &a[i]);
        int &r = mp[a[i]];
        if(r){
            prv[i] = r;
            nxt[r] = i;
        }
        r = i;
    }

    wavelet wt(prv);
    VV(int) G(m + 1);
    for(int i = 1; i <= m; ++i){
        if(prv[i] > 0){
            int t = prv[i];
            unsigned u = wt.ltrmq(t + 1, i, t);
            if(~u && u){
                G[i].emplace_back(u - 1);
            }
            
            int w = prv[prv[prv[i]]];
            if(w > 0){
                G[i].emplace_back(w - 1);
            }
        }
    }

    vint dp(m + 2, -10101010);
    dp[m + 1] = 0;
    vector<int> tag(m + 2, m + 1);
    for(int i = m; i >= 0; --i){
        if(dp[i] < dp[i + 1]){
            dp[i] = dp[i + 1];
            tag[i] = -1;
        }
        for(size_t j = 0; j < G[i].size(); ++j){
            int t = G[i][j];
            if(dp[t] <= dp[i]){
                dp[t] = dp[i] + 1;
                tag[t] = i;
            }
        }
    }

    int s = 0;
    vector<int> res;
    while(dp[s]){
        if(tag[s] < 0){
            ++s;
        }
        else{
            res.push_back(a[s + 1]);
            s = tag[s];
            res.push_back(a[s]);
        }
    }
    
    int k = res.size();
    printf("%d\n", k * 2);
    const char *spl = "";
    for(int i = 0; i < k; i += 2){
        int x = res[i], y = res[i + 1];
        printf("%s%d %d %d %d", spl, x, y, x, y);
        spl = " ";
    }
    puts("");
}