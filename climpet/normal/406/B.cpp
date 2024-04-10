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
    int s = 1000000;
    vector<char> rem(s + 1, 1);
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        rem[x] = 0;
    }

    vector<int> ans, cand;
    int cnt = 0;
    for(int i = 1; i <= s; ++i){
        if(rem[i] && !rem[s - i + 1]){
            ans.push_back(i);
        }
        else if(i * 2 <= s && rem[i] == rem[s - i + 1]){
            if(rem[i]){
                cand.push_back(i);
            }
            else{
                ++cnt;
            }
        }
    }
    
    for(int i = 0; i < cnt; ++i){
        ans.push_back(cand[i]);
        ans.push_back(s - cand[i] + 1);
    }

    printf("%d\n", (int)ans.size());
    for(int i = ans.size(); i--; ){
        printf("%d%c", ans[i], i ? ' ' : '\n');
    }
}