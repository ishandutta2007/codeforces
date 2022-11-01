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
    int x, k, a, b, c;
    cin >> x >> k;
    int cnt = x - 1;
    vector<int> t(x + 1);
    t[x] = 1;

    for(int i = 0; i < k; ++i){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            cnt -= 2;
            t[b] = t[c] = 1;
        }
        else{
            cin >> b;
            --cnt;
            t[b] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i < x; ++i){
        if(!t[i]){
            ++ans;
            if(!t[i + 1]){
                ++i;
            }
        }
    }
    
    cout << ans << ' ' << cnt << endl;
}