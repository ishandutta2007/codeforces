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


struct student{
    int idx, b, c;
    bool operator< (const student &s) const{
        return b < s.b;
    }
};


int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    LL s;
    cin >> n >> m >> s;

    vector<pii> as(m);
    vector<student> ps(n + 1);

    for(int i = 0; i < m; ++i){
        cin >> as[i].first;
        as[i].second = i;
    }
    for(int i = 1; i <= n; ++i){
        cin >> ps[i].b;
    }
    for(int i = 1; i <= n; ++i){
        cin >> ps[i].c;
    }
    for(int i = 0; i <= n; ++i){
        ps[i].idx = i;
    }
    ps[0].b = -1;
    ps[0].c = s + 1;
    sort(ALL(ps));
    sort(ALL(as));

    vector<int> ans;

    int left = 1, right = n + 3;
    vector<int> res(m);
    while(left < right){
        int mid = (left + right) >> 1;
        LL sum = 0;
        int k = n;
        priority_queue<pii> pq;

        bool ok = true;
        for(int i = m - 1; i >= 0; i -= mid){
            while(as[i].first <= ps[k].b){
                pq.push(pii(-ps[k].c, k));
                --k;
            }

            if(pq.empty()){
                ok = false;
                break;
            }
            
            sum -= pq.top().first;
            int t = pq.top().second;
            pq.pop();
            for(int j = 0; j < mid && i - j >= 0; ++j){
                res[as[i - j].second] = ps[t].idx;
            }
        }

        if(ok && sum <= s){
            ans = res;
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    if(ans.empty()){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i = 0; i < m; ++i){
            printf("%d%c", ans[i], i + 1 == m ? '\n': ' ');
        }
    }
}