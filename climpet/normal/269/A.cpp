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



int main(){
    int n;
    scanf("%d", &n);
    vector<pii> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a.begin(), a.end());

    LL t = 0;
    int u = 0;
    for(int i = 0; i < n; ++i){
        int d = min(a[i].first - u, 30);
        LL x = 1LL << (2 * d);
        LL y = (t + x - 1) / x;

        t = max<LL>(a[i].second, y);
        u = a[i].first;
    }

    int p = a.back().first;
    do{
        ++p;
        t = (t + 3LL) >> 2;
    } while(t > 1);
    
    printf("%d\n", p);
}