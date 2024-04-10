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



int main(){
    int n;
    cin >> n;
    vint a(n), b(n);
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        for(int j = 0; j < n; ++j){
            if(s[i][j] == '.'){
                ++a[i];
                ++b[j];
            }
        }
    }
    
    int ma = *min_element(ALL(a)), mb = *min_element(ALL(b));
    if(!ma && !mb){
        puts("-1");
        return 0;
    }
    if(ma){
        for(int i = 0; i < n; ++i){
            int j;
            for(j = 0; s[i][j] == 'E'; ++j);
            printf("%d %d\n", i + 1, j + 1);
        }
    }
    else{
        for(int j = 0; j < n; ++j){
            int i;
            for(i = 0; s[i][j] == 'E'; ++i);
            printf("%d %d\n", i + 1, j + 1);
        }
    }
}