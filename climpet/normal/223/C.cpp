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
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


#define MOD 1000000007

int a[2000];
int n;


typedef vector<int> vint;
vint tmp;

inline void mul(vint &v1, const vint &v2){
    for(int i = 0; i < n; ++i){
        int a = 0;
        int k = n - 1;
        for(int j = i; j < n; ++j, --k){
            a += (LL)v1[j] * v2[k] % MOD;
            if( a >= MOD ) a -= MOD;
        }
        tmp[i] = a;
    }
    
    v1.swap(tmp);
}


int main(){
    int k;
    scanf("%d%d", &n, &k);
    tmp.resize(n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    vint y(n, 1);
    vint x(n);
    x.back() = 1;

    while(k){
        if( k & 1 ) mul(x, y);
        mul(y, y);
        k >>= 1;
    }

    for(int i = 0; i < n; ++i){
        int z = 0;
        int k = n - 1;
        for(int j = i; j >= 0; --j, --k){
            z += (LL)x[k] * a[j] % MOD;
            if( z >= MOD ) z -= MOD;
        }
        printf("%d%c", z, i == n - 1 ? '\n' : ' ');
    }

}