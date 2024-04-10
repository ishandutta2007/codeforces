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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


#define MAX 1000000

int ng[MAX + 10];
int a[5010];
int c[MAX + 10];


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int z = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        z = max(z, a[i]);
        for(int j = 0; j < i; ++j){
            ++ng[abs(a[i] - a[j])];
        }
    }

    int lim = k * (k + 1) / 2;
    for(int m = n - k; ; ++m){
        int x = 0;
        for(int i = 0; i <= z; i += m){
            x += ng[i];
        }
        if(x <= lim){
            x = k;
            for(int i = 0; i < n; ++i){
                if(c[a[i] % m]++){
                    if(--x < 0){
                        break;
                    }
                }
            }
            if(x >= 0){
                printf("%d\n", m);
                return 0;
            }
            memset(c, 0, sizeof(int) * m);
        }
    }
}