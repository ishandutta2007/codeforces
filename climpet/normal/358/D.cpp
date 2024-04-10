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


int a[4][3010];
int moves[4][2] = {
    {1, 2},
    {1, 2},
    {3, 0},
    {3, 0}
};


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = 0; j < n; ++j){
        a[3][j] = a[1][j];
    }

    vector<int> dp1(4), dp2(4);
    dp1[0] = a[0][0];
    dp1[1] = dp1[2] = INT_MIN;
    dp1[3] = a[3][0];

    for(int i = 1; i < n; ++i){
        fill(dp2.begin(), dp2.end(), INT_MIN);
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 2; ++k){
                int m = moves[j][k];
                int &t = dp2[m];
                t = max(t, dp1[j] + a[m][i]);
            }
        }
        dp1.swap(dp2);
    }
    
    int ans = max(dp1[0], dp1[1]);
    printf("%d\n", ans);
}