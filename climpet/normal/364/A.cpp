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
    int a;
    string s;
    cin >> a >> s;

    LL n = s.size();

    vector<int> v(n + 1);
    for(int i = 0; i < n; ++i){
        v[i + 1] = v[i] + s[i] - '0';
    }

    map<int,int> mp;
    map<int,int>::iterator it;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < i; ++j){
            ++mp[v[i] - v[j]];
        }
    }

    LL ans = 0;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < i; ++j){
            int p = v[i] - v[j];
            if(!p){
                if(!a){
                    ans += n * (n + 1) / 2;
                }
            }
            else if(a % p == 0){
                it = mp.find(a / p);
                if(it != mp.end()){
                    ans += it->second;
                }
            }
        }
    }
    
    cout << ans << endl;
}