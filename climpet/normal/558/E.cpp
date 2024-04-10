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
#include <cassert>

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


namespace{
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


struct segtree{
    int m;
    vint lz, sum;

    explicit segtree(int n){
        m = 1;
        while(m < n){ m <<= 1; }
        lz.assign(m * 2 - 1, -1);
        sum.assign(m * 2 - 1, 0);
    }
    
    void eval(int k, int l, int r){
        if(k <= m - 2){
            if(lz[k] != -1){
                int t = (r - l) * lz[k];
                lz[k * 2 + 1] = lz[k * 2 + 2] = lz[k];
                sum[k * 2 + 1] = sum[k * 2 + 2] = t >> 1;
                lz[k] = -1;
            }
            sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
        }
    }

    void assign(int a, int b, int v){
        assign(a, b, v, 0, 0, m);
    }
    int assign(int a, int b, int v, int k, int l, int r){
        eval(k, l, r);
        if(r <= a || b <= l){ }
        else if(a <= l && r <= b){
            lz[k] = v;
            sum[k] = v * (r - l);
        }
        else{
            int x = assign(a, b, v, k * 2 + 1, l, (l + r) >> 1);
            int y = assign(a, b, v, k * 2 + 2, (l + r) >> 1, r);
            sum[k] = x + y;
        }
        return sum[k];
    }
    int getsum(int a, int b){
        return getsum(a, b, 0, 0, m);
    }
    int getsum(int a, int b, int k, int l, int r){
        eval(k, l, r);
        if(r <= a || b <= l){ return 0; }
        if(a <= l && r <= b){
            return sum[k];
        }
        int x = getsum(a, b, k * 2 + 1, l, (l + r) >> 1);
        int y = getsum(a, b, k * 2 + 2, (l + r) >> 1, r);
        return x + y;
    }
};


void mainmain(){
    int n, q;
    string s = "_";
    cin >> n >> q >> s;
    
    vector<segtree> segs;
    segs.reserve(26);
    for(int i = 0; i < 26; ++i){
        segs.emplace_back(n);
    }
    for(int i = 0; i < n; ++i){
        int x = s[i] - 'a';
        segs[x].assign(i, i + 1, 1);
    }
    
    for(int i = 0; i < q; ++i){
        int lt, rt, tp;
        cin >> lt >> rt >> tp;
        --lt;
        
        int j, en, dif;
        if(tp){
            j = 0;
            en = 26;
            dif = 1;
        }
        else{
            j = 25;
            en = -1;
            dif = -1;
        }
        
        int cnt = 0;
        for(; j != en; j += dif){
            int c = segs[j].getsum(lt, rt);
            segs[j].assign(lt, rt, 0);
            segs[j].assign(lt + cnt, lt + cnt + c, 1);
            cnt += c;
        }
    }
    
    s.assign(n, '_');
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j){
            int c = segs[j].getsum(i, i + 1);
            if(c == 1){
                s[i] = j + 'a';
                break;
            }
        }
    }
    
    cout << s << '\n';
}



}
int main() try{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}