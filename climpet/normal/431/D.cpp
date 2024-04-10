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
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8

typedef unsigned long long ULL;

ULL func(ULL x, int k){
    vector<ULL> cnt1(k + 1), cnt2(k + 1);
    cnt1[0] = 1;
    for(int i = 63; i >= 0; --i){
        for(int j = k; j > 0; --j){
            cnt2[j] += cnt2[j - 1];
        }

        if(x >> i & 1){
            for(int j = k; j >= 0; --j){
                cnt2[j] += cnt1[j];
            }
            for(int j = k; j > 0; --j){
                cnt1[j] = cnt1[j - 1];
            }
            cnt1[0] = 0;
        }
    }
    return cnt1[k] + cnt2[k];
}

int main(){
    ULL m;
    int k;
    cin >> m >> k;
    
    ULL left = 1, right = 1000000000000000001ull;
    while(left + 1 < right){
        ULL mid = (left + right) / 2;
        ULL t1 = func(mid * 2, k);
        ULL t2 = func(mid, k);
        ULL t = t1 - t2;
        if(t <= m){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << left << endl;
}