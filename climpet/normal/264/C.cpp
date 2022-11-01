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

int v[100000], c[100000];
LL p[100001];

int main(){
    int n, q;
    LL a, b;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; ++i)
        scanf("%d", v + i);
    for(int i = 0; i < n; ++i)
        scanf("%d", c + i);

    for(; q--; ){
        scanf("%I64d%I64d", &a, &b);
        memset(p, 192, sizeof p);

        LL max1 = p[0], max2 = p[0];
        LL ans = 0;
        for(int i = 0; i < n; ++i){
            LL t = max(v[i] * b, p[c[i]] + v[i] * a);
            if(max1 == p[c[i]]){
                t = max(t, max2 + v[i] * b);
            }
            else{
                t = max(t, max1 + v[i] * b);
            }

            if(ans < t) ans = t;

            if(max1 == p[c[i]]){
                if(max1 < t){
                    max1 = t;
                }
            }
            else if(t > max1){
                max2 = max1;
                max1 = t;
            }
            else if(t > max2){
                max2 = t;
            }

            if(p[c[i]] < t) p[c[i]] = t;
        }
        printf("%I64d\n", ans);
    }
}