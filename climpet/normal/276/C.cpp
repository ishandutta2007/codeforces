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
    int n, q, l, r;
    scanf("%d%d", &n, &q);

    vector<int> a(n), imos(n + 1);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    sort(ALL(a), greater<int>());

    for(int i = 0; i < q; ++i){
        scanf("%d%d", &l, &r);
        ++imos[l - 1];
        --imos[r];
    }
    for(int i = 1; i <= n; ++i){
        imos[i] += imos[i-1];
    }
    sort(ALL(imos), greater<int>());

    LL ans = 0;
    for(int i = 0; i < n; ++i){
        ans += (LL)a[i] * imos[i];
    }
    cout << ans << endl;
}