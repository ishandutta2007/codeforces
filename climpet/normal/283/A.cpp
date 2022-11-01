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
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

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


struct BIT{
    vector<LL> b;

    BIT(): b(200020) {
    }

    LL sum(int i){
        LL s = 0;
        while(i > 0){
            s += b[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int v){
        while(i < b.size()){
            b[i] += v;
            i += i & -i;
        }
    }
};

BIT b0, b1;

void add_range(int l, int r, int x){
    b0.add(l, -x * (l - 1));
    b1.add(l, x);
    b0.add(r + 1, x * r);
    b1.add(r + 1, -x);
}


int main(){
    int n, t, a, x;
    int sz = 1;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d%d", &a, &x);
            a = min(a, sz);
            add_range(1, a, x);
        }
        else if(t == 2){
            scanf("%d", &x);
            ++sz;
            add_range(sz, sz, x);
        }
        else if(sz > 1){
            LL u = b0.sum(sz) + b1.sum(sz) * sz;
            u -= b0.sum(sz - 1) + b1.sum(sz - 1) * (sz - 1);
            add_range(sz, sz, -u);
            --sz;
        }

        LL s = b0.sum(sz) + b1.sum(sz) * sz;
        printf("%.10f\n", s / (double)sz);
    }
}