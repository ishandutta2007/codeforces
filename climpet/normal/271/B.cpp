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

bool isnp[110010];

int main(){
    for(int i = 2; i < 400; ++i)
        if(!isnp[i])
            for(int j = i * i; j <= 110000; j += i)
                isnp[j] = true;

    vector<int> primes;
    for(int i = 2; i < 110000; ++i){
        if(!isnp[i]) primes.push_back(i);
    }

    int n, m, x;
    scanf("%d%d", &n, &m);
    vvint v1(n, vint(m));
    vvint v2(m, vint(n));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        scanf("%d", &x);
        v1[i][j] = v2[j][i] = *lower_bound(primes.begin(), primes.end(), x) - x;
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        ans = min(ans, accumulate(v1[i].begin(), v1[i].end(), 0));
    }
    for(int j = 0; j < m; ++j){
        ans = min(ans, accumulate(v2[j].begin(), v2[j].end(), 0));
    }
    
    printf("%d\n", ans);
}