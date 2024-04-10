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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8

int n, m;
int a[1024][1024];

char cnt[1048576];
vint v;

bool check(int md){
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; ++i){
        v.clear();
        for(int j = 0; j < m; ++j){
            if(a[i][j] >= md){
                for(int k = 0; k < v.size(); ++k){
                    if(++cnt[j << 10 | v[k]] > 1){
                        return true;
                    }
                }
                v.push_back(j);
            }
        }
    }
    return false;
}

int main(){
    v.reserve(1024);
    srand(time(0));
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        scanf("%d", &a[i][j]);
    }

    int left = 0, right = 1000000010;
    while(left + 1 < right){
        int md = (left + right) >> 1;
        if(check(md)){
            left = md;
        }
        else{
            right = md;
        }
    }
    printf("%d\n", left);
}