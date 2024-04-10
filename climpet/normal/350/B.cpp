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
    int n;
    scanf("%d", &n);
    vector<int> tp(n + 1), a(n + 1), c(n + 1);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &tp[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        ++c[a[i]];
    }
    
    c[0] = 2;

    vector<int> ans, tmp;
    for(int i = 1; i <= n; ++i){
        if(tp[i] == 1){
            tmp.clear();
            int v = i;
            while(c[v] < 2){
                tmp.push_back(v);
                v = a[v];
            }
            if(tmp.size() > ans.size()){
                ans.swap(tmp);
            }
        }
    }

    char spl = '\n';
    printf("%d", ans.size());
    for(int i = ans.size() - 1; i >= 0; --i){
        printf("%c%d", spl, ans[i]);
        spl = ' ';
    }
    puts("");
}