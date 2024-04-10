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


int cnt1[100010];

typedef map<int,int>::iterator iter;

inline iter findbest(int m, int x, map<int,int> &mp){
    int y = m - 1 - x;
    if(y < 0){ y += m; }
    iter it = mp.upper_bound(y);
    if(it == mp.begin()){ it = mp.end(); }
    --it;
    return it;
}


int main(){
    int n, m, d;
    scanf("%d%d", &n, &m);

    map<int,int> cnt2;
    iter it;
    for(int i = 0; i < n; ++i){
        scanf("%d", &d);
        ++cnt1[d];
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &d);
        ++cnt2[d];
    }

    priority_queue<pii> pq;
    for(int i = 0; i < m; ++i){
        if(cnt1[i]){
            it = findbest(m, i, cnt2);
            int s = i + it->first;
            if(s >= m){ s -= m; }
            pq.push(pii(s, i));
        }
    }

    vint ans;
    ans.reserve(n);
    while(!pq.empty() && !cnt2.empty()){
        pii p = pq.top();
        pq.pop();
        
        int s = p.first;
        int t = p.second;
        int u = s - t;
        if(u < 0){ u += m; }

        it = cnt2.find(u);
        if(it == cnt2.end()){
            it = findbest(m, t, cnt2);
            s = t + it->first;
            if(s >= m){ s -= m; }
            pq.push(pii(s, t));
        }
        else{
            ans.push_back(s);
            int k = --it->second;
            if(!k){
                cnt2.erase(it);
            }
            if(--cnt1[t]){
                if(!k){ it = findbest(m, t, cnt2); }
                s = t + it->first;
                if(s >= m){ s -= m; }
                pq.push(pii(s, t));
            }
        }
    }
    
    for(int i = 0; i < ans.size(); ++i){
        if(i != 0){ putchar(' '); }
        printf("%d", ans[i]);
    }
    puts("");
}