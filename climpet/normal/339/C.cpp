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
    int m;
    string s;
    cin >> s >> m;

    int center = 15;
    int dp[1010][31][11] = {};
    dp[0][center][0] = 1;
    
    int init[2] = {0, center + 1};
    int lim[2] = {center, 31};
    int sgn[2] = {-1, 1};
    
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= s.size(); ++j){
            if(s[j - 1] == '1'){
                for(int k = init[i & 1]; k < lim[i & 1]; ++k){
                    for(int h = 0; h <= 10; ++h){
                        if(j != h && dp[i - 1][k - sgn[i & 1] * j][h]){
                            dp[i][k][j] = ~h;
                        }
                    }
                }
            }
        }
    }

    int p, t = 100;
    for(p = init[m & 1]; ; ++p){
        if(p == lim[m & 1]){
            puts("NO");
            return 0;
        }

        for(t = 0; t <= 10; ++t){
            if(dp[m][p][t]){
                break;
            }
        }
        if(t <= 10){ break; }
    }

    stack<int> st;
    for(int i = m; i > 0; --i){
        st.push(t);
        int q = p - t * sgn[i & 1];
        t = ~dp[i][p][t];
        p = q;
    }
    
    printf("YES");
    char spl = '\n';
    while(!st.empty()){
        printf("%c%d", spl, st.top());
        spl = ' ';
        st.pop();
    }
    puts("");
}