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
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8



template <class Tp>
class fenwick_tree{
    std::vector<Tp> bit;
public:
    fenwick_tree(){}
    explicit fenwick_tree(std::size_t n) : bit(n + 1) {}
    Tp sum(std::size_t i) const{
        Tp s = 0;
        while(i){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(std::size_t i, Tp x){
        while(i < bit.size()){
            bit[i] += x;
            i += i & -i;
        }
    }
    void clear(){
        bit.clear();
    }
    void assign(std::size_t n){
        bit.assign(n + 1, Tp());
    }
    void swap(fenwick_tree &f){
        bit.swap(f.bit);
    }
};




int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n + 1), b(k), rt(n + 1);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        rt[a[i]] = i;
    }
    for(int i = 0; i < k; ++i){
        scanf("%d", &b[i]);
    }
    
    vector<int> sb = b;
    sort(ALL(sb));
    sb.push_back(INT_MAX);
    
    fenwick_tree<int> ft(n + 2);
    for(int i = 1; i <= n; ++i){
        ft.add(i, 1);
    }

    LL ans = 0;
    set<int> st;
    st.insert(0);
    st.insert(n + 1);
    int u = 0;
    for(int i = 1; i <= n; ++i){
        if(i == sb[u]){
            ++u;
            st.insert(rt[i]);
        }
        else{
            set<int>::iterator it1, it2;
            it1 = it2 = st.upper_bound(rt[i]);
            --it1;
            ans += ft.sum(*it2 - 1) - ft.sum(*it1);
        }
        ft.add(rt[i], -1);
    }
    
    cout << ans << endl;
}