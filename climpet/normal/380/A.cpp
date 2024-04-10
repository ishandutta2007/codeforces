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


inline void output(int x, queue<LL> &q){
    q.pop();
    cout << x << (q.size() == 1 ? '\n' : ' ');
}


int main(){
    ios::sync_with_stdio(false);

    int m;
    cin >> m;
    vector<int> ls(m), cs(m, -1);
    for(int i = 0; i < m; ++i){
        int t;
        cin >> t >> ls[i];
        if(t == 2){
            cin >> cs[i];
        }
    }

    cin >> m;
    queue<LL> q;
    for(int i = 0; i < m; ++i){
        LL x;
        cin >> x;
        q.push(x - 1);
    }
    q.push(LLONG_MAX);

    LL len = 0;
    vector<int> v;
    const size_t lim = 100010;

    for(size_t i = 0; i < ls.size(); ++i){
        if(cs[i] < 0){
            if(v.size() < lim){
                v.push_back(ls[i]);
            }
            ++len;
            
            if(q.front() < len){
                output(ls[i], q);
            }
        }
        else{
            int t = cs[i];
            while(v.size() < lim && t > 0){
                --t;
                v.resize(v.size() + ls[i]);
                copy(v.begin(), v.begin() + ls[i], v.end() - ls[i]);
            }

            LL plen = len;
            len += (LL)ls[i] * cs[i];
            
            while(q.front() < len){
                if(q.front() < v.size()){
                    output(v[q.front()], q);
                }
                else{
                    output(v[(q.front() - plen) % ls[i]], q);
                }
            }
        }
    }
}