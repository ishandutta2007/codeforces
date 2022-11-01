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



int main(){
    LL l, r;
    size_t k;
    cin >> l >> r >> k;
    vector<LL> ans;

    LL d = r - l + 1;

    if(d < 15){
        LL m = LLONG_MAX;
        for(LL T = 1 << d; --T; ){
            if(bitset<32>(T).count() > k){ continue; }
            LL x = 0;
            for(LL i = 0; i < d; ++i){
                if(T >> i & 1){
                    x ^= l + i;
                }
            }
            if(m > x){
                m = x;
                ans.clear();
                for(LL i = 0; i < d; ++i){
                    if(T >> i & 1){
                        ans.push_back(l + i);
                    }
                }
            }
        }
    }
    else if(k == 1){
        ans.push_back(l);
    }
    else if(k == 2){
        LL t = (r - 7) / 4 * 4;
        ans.push_back(t);
        ans.push_back(t + 1);
    }
    else if(k == 3){
        LL p = 1;
        while(p < l){
            p = p << 1 | 1;
        }
        LL q = p + p / 2 + 2;
        if(q <= r){
            ans.push_back(p);
            ans.push_back(q - 1);
            ans.push_back(q);
        }
        else{
            LL t = (r - 7) / 4 * 4;
            ans.push_back(t);
            ans.push_back(t + 1);
        }
    }
    else{
        LL t = (r - 7) / 4 * 4;
        for(LL i = 0; i < 4; ++i){
            ans.push_back(t + i);
        }
    }
    
    LL res = 0;
    for(LL x : ans){
        res ^= x;
    }
    cout << res << '\n' << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); ++i){
        if(i != 0){ cout << ' '; }
        cout << ans[i];
    }
    cout << endl;
}