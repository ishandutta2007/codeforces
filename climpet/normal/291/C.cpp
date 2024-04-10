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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



int main(){
    typedef unsigned uint;

    int k, n;
    uint a0, a1, a2, a3;
    scanf("%d%d", &n, &k);
    vector<uint> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%u.%u.%u.%u", &a0, &a1, &a2, &a3);
        v[i] = a0 << 24 | a1 << 16 | a2 << 8 | a3;
    }

    uint ans = 0;
    for(int i = 31; ; --i){
        if(i < 0){
            puts("-1");
            return 0;
        }

        ans |= 1u << i;
        set<uint> st;
        for(int i = 0; i < n; ++i){
            st.insert(v[i] & ans);
        }
        if(st.size() == k){
            break;
        }
    }
    
    printf("%u.%u.%u.%u\n", ans >> 24 & 255, ans >> 16 & 255,
                            ans >> 8 & 255, ans & 255
    );
}