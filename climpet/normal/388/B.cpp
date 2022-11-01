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



int main(){
    int k;
    scanf("%d", &k);
    
    int n = 200;
    vector<string> ans(n, string(n, 'N'));
    
    ans[0][2] = 'Y';
    for(int i = 0; i <= 30; ++i){
        for(int j = 2; j <= 3; ++j)
        for(int h = 4; h <= 5; ++h){
            ans[i * 2 + j][i * 2 + h] = 'Y';
        }
    }
    
    for(int i = 0; i <= 40; ++i){
        ans[i + 100][i + 101] = 'Y';
    }
    ans[140][1] = 'Y';
    
    for(int i = 0; i <= 30; ++i){
        if(k >> i & 1){
            ans[i * 2 + 2][i + 100] = ans[i * 2 + 3][i + 100] = 'Y';
        }
    }

    
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        if(ans[i][j] == 'Y'){
            ans[j][i] = 'Y';
        }
    }
    
    printf("%d\n", n);
    for(int i = 0; i < n; ++i){
        puts(ans[i].c_str());
    }
}