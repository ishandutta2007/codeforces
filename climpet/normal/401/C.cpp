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
    int n, m;
    cin >> n >> m;
    string ans(n + m, 'x');

    if(n == m + 1){
        for(int i = 0; i < n + m; ++i){
            ans[i] = i % 2 + '0';
        }
    }
    else if(n <= m){
        int a = n, b = m;
        
        int i;
        for(i = 0; i < n + m; ){
            if(a < b && i + 2 < n + m){
                ans[i] = ans[i + 1] = '1';
                ans[i + 2] = '0';
                --a;
                b -= 2;
                i += 3;
            }
            else if(a == b && i + 1 < n + m){
                ans[i] = '1';
                ans[i + 1] = '0';
                --a;
                --b;
                i += 2;
            }
            else{
                if(i < n + m && b){
                    ans[i++] = '1';
                    --b;
                }
                if(i < n + m && b){
                    ans[i++] = '1';
                    --b;
                }
                if(i < n + m && a){
                    ans[i++] = '0';
                    --a;
                }
            }
        }
        
        if(a || b){
            ans = "-1";
        }
    }
    else{
        ans = "-1";
    }
    
    cout << ans << endl;
}