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



int main(){
    int n, t, w;
    vector<int> v[2], s[2];
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> t >> w;
        v[t-1].push_back(w);
    }
    for(int i = 0; i < 2; ++i){
        sort(ALL(v[i]));
        s[i].resize(v[i].size() + 1);
        for(int j = 0; j < v[i].size(); ++j){
            s[i][j+1] = s[i][j] + v[i][j];
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i <= v[0].size(); ++i)
    for(int j = 0; j <= v[1].size(); ++j){
        t = (v[0].size() - i) + 2 * (v[1].size() - j);
        w = s[0][i] + s[1][j];
        if(w <= t && ans > t){
            ans = t;
        }
    }
    cout << ans << endl;
}