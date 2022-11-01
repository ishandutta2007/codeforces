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
    LL n, m, p;
    cin >> n >> m >> p;
    vector<LL> a(n), b(m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &b[i]);
    }
    
    map<LL,int> mp;
    for(int i = 0; i < m; ++i){
        ++mp[b[i]];
    }
    map<LL,int>::iterator it;

    vector<LL> ans;
    for(LL k = 0; k < p; ++k){
        LL c = 0;
        for(int i = 0; i < m && i * p + k < n; ++i){
            int x = a[i * p + k];
            it = mp.find(x);
            if(it != mp.end() && --it->second == 0){
                ++c;
            }
        }
        
        LL t = k;
        while(1){
            if(c == mp.size()){
                ans.push_back(t + 1);
            }
            if(t + m * p > n){
                break;
            }

            it = mp.find(a[t]);
            if(it != mp.end() && ++it->second == 1){
                --c;
            }
            it = mp.find(a[t + m * p]);
            if(it != mp.end() && --it->second == 0){
                ++c;
            }
            t += p;
        }

        while(t < n){
            it = mp.find(a[t]);
            if(it != mp.end()){
                ++it->second;
            }
            t += p;
        }
    }
    
    sort(ALL(ans));
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i){
        if(i != 0){ cout << ' '; }
        cout << ans[i];
    }
    cout << endl;
}